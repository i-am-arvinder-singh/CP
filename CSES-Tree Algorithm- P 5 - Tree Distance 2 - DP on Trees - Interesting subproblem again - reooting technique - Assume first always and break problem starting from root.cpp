#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
#define ll              long long
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=(int)a; i<(int)b; i++)
#define bfl(i,a,b)      for(int i=(int)a-1; i>=(int)b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define omniphantom     ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)         2*x+2

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class dpOnTrees{
    vector<vector<int>> edges;
    vector<int> nodesInSubtree;
    vector<int> sumOfDistancesInSubtree;
    vector<int> ans;
    int n;
public:
    dpOnTrees(vector<vector<int>> edges, int n){
        this->edges = edges;
        this->n = n;
        nodesInSubtree = vector<int> (n+3,0);
        sumOfDistancesInSubtree = vector<int> (n+3,0);
        ans = vector<int> (n+3,0);
    }

    void solve(){
        depthDfs(1,-1);
        distanceDfs(1,-1); 
        solve(1,-1,0);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }   

    int depthDfs(int node, int par){
        int ans = 0;
        for(auto child : edges[node]){
            if(child==par) continue;
            ans += depthDfs(child,node);
        }
        return nodesInSubtree[node] = ans + 1;
    }

    int distanceDfs(int node, int par){
        int ans = 0;
        for(auto child : edges[node]){
            if(child==par) continue;
            ans += (distanceDfs(child,node)+nodesInSubtree[child]);
        }
        return sumOfDistancesInSubtree[node] = ans;
    }

    void solve(int node, int par, int par_ans){
        ans[node] = par_ans + sumOfDistancesInSubtree[node] + n - nodesInSubtree[node];
        for(auto child:edges[node]){
            if(child == par) continue;
            solve(child,node,ans[node]-(sumOfDistancesInSubtree[child]+nodesInSubtree[child]));
        }
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> edges(n+2);
    for(int i=2;i<=n;i++){
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    dpOnTrees t(edges,n);
    t.solve();
}

int32_t main()
{
	omniphantom
	#if 0
	w(t)
	#endif // 0
    solve();
	return 0;
}

