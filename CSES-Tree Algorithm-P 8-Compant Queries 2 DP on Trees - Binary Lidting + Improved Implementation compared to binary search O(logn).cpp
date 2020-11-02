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

class binaryLifting{
    vector<vector<int>> edges;
    vector<int> lvl;
    vector<vector<int>> dp;
    int n,q;
public:
    binaryLifting(vector<vector<int>> edges, int n, int q){
        this->edges = edges;
        this->dp  = vector<vector<int>> (n+3,vector<int>(22,-1));
        this->n   = n;
        this->q   = q;
        this->lvl = vector<int> (n+3,0);
    }

    void solve(){
        dfs(1,-1, 0);
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            cout<<LCA(x,y)<<endl;
        }
    }       

    void dfs(int node, int par, int level){
        lvl[node] = level;
        dp[node][0] = par;
        for(int i=1; i<=21;i++){
            if(dp[node][i-1]!=-1) dp[node][i] = dp[(dp[node][i-1])][i-1];
            else                  dp[node][i] = -1;
        }
        for(auto child : edges[node]){
            if(child==par) continue;
            dfs(child,node,level+1);
        }
    }

    int lift(int node, int jump){
        int init = node;
        for(int i=21;i>=0;i--){
            int val = (1ll<<i);
            if(val&jump) init = dp[init][i];
            if(init==-1) return -1;
        }
        return init;
    }

    int LCA(int x, int y){
        if(lvl[x]<lvl[y]) swap(x,y);
        x = lift(x,lvl[x]-lvl[y]);
        if(x==y) return x;
        //Keep in mind that you are applying binary search on jump
        for(int i=21;i>=0;i--){
            int val = (1ll<<i);
            if(dp[x][i]!=dp[y][i]){
                x = lift(x, val);
                y = lift(y, val);
            }
        }
        return lift(x,1);
    }

};

void solve()
{
    int n, q;
    cin>>n>>q;
    vector<vector<int>> edges(n+2);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        edges[x].pb(i);
        edges[i].pb(x);
    }
    binaryLifting t(edges,n,q);
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

