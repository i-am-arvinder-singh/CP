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
    vector<vector<int>> dp;
    int n;
public:
    dpOnTrees(vector<vector<int>> edges, int n){
        this->edges = edges;
        this->n = n;
        dp = vector<vector<int>> (n+4,vector<int>(3,-1));
    }

    int solve(){
        return max(dfs(1,0,-1),dfs(1,1,-1)); // 0->node is not included
                                       // 1->node is     included
    }

    int dfs(int node, int trans, int par){
        //node is not included i.e., trans == 0
        if(dp[node][trans]!=-1) return dp[node][trans];
        vector<int> childrens = edges[node];
        int sum = 0;
        vector<int> dfs0,dfs1;
        dfs0.push_back(0);
        dfs1.push_back(0);
        for(int i=0;i<(int)childrens.size();i++){
            int child = childrens[i];
            if(child==par) continue;
            dfs0.pb(dfs(child,0,node));
            dfs1.pb(dfs(child,1,node));
            sum+=max(dfs0.back(),dfs1.back());
        } 
        dfs0.push_back(0);
        dfs1.push_back(0);
        if(trans==0) return dp[node][trans] = sum;
        //node is included i.e., trans == 1
        int ans = 0;
        vector<int> pref;
        for(int i=0;i<(int)dfs0.size();i++) pref.pb(max(dfs0[i],dfs1[i]));
        for(int i=1;i<(int)pref.size();i++) pref[i]=pref[i]+pref[i-1];
        for(int i=1;i<(int)pref.size()-1;i++){
            ans=max(ans, pref[i-1] + dfs0[i] + pref.back() - pref[i] + 1);
        }
        return dp[node][trans] = ans;
    }   
};

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n+2);
    vector<vector<int>> edges(n+2);
    for(int i=2;i<=n;i++){
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    dpOnTrees t(edges,n);
    cout<<t.solve();
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

