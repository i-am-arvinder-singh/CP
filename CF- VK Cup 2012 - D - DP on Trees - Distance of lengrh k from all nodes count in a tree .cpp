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
    vector<int> ans;
    vector<vector<int>> dp1,dp2;
    int n,k;
public:
    dpOnTrees(vector<vector<int>> edges, int n, int k){
        this->edges = edges;
        this->dp1   = vector<vector<int>> (n+3,vector<int>(503,0));
        this->dp2   = vector<vector<int>> (n+3,vector<int>(503,0));
        this->n = n;
        this->k = k;
    }

    void solve(){
        dfs(1,-1);
        solve(1,-1);
        int ans = 0;
        for(int i=1;i<=n;i++) ans+=dp2[i][k];
        cout<<ans/2<<endl;
    }       

    void dfs(int node, int par){
        for(auto child:edges[node]){
            if(child==par) continue;
            dfs(child,node);
        }
        dp1[node][0] = 1;
        for(int i=1; i<=k; i++){
            for(auto child : edges[node]){
                if(child==par) continue;
                dp1[node][i] += dp1[child][i-1];
            }
        }
    }

    void solve(int node, int par){
        for(int i=0;i<=k;i++){
            if(par!=-1) dp2[node][i] = dp1[node][i]+(i-1>=0?dp2[par][i-1]:0)-((i-2>=0)?dp1[node][i-2]:0);
            else if(par==-1) dp2[node][i] = dp1[node][i];
        }
        for(auto child:edges[node]){
            if(child==par) continue;
            solve(child,node);
        }
    }
};

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> edges(n+2);
    for(int i=2;i<=n;i++){
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    dpOnTrees t(edges,n,k);
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

