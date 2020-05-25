#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini mx = 2e5+5;
vi g[mx];
int col[mx];
int vis[mx];
int dp[mx][2];

void dfs(int u)
{
    vis[u]=1;
    dp[u][1]=col[u];
    dp[u][0]=1-col[u];
    for(auto v:g[u]){
        if(vis[v]) continue;
        dfs(v);
        int white = dp[u][0], black = dp[u][1];
        //To understand this problem we must really understand that
        //the dp is not only applied to parent and child
        //but it is also getting applied child wise with respect to a particular parent
        //It is really important to understand the above thing

        //parent also keeps getting updated after computations for a child is done.
        //until the process is done for all child.

        //Take one child at a time and continue.

        //number of only whites is already stored in the "white" variable
        //number of exactly one black is stored in the "black" variable
        //above is w.r.t previous computations


        //now we start to update our dp

        //Two possibilities:
        //1. Include this(current) child
        //2. Not include this(current) child

        //INCLUDE CURRENT CHILD
        dp[u][0]=(white*dp[v][0])%mod;
        dp[u][1]=(black*dp[v][0]+white*dp[v][1])%mod;

        //NOT INCLUDE CURRENT CHILD
        dp[u][0]+=white*dp[v][1];
        dp[u][0]%=mod;
        //Kyuki isko alag kiya toh black ke sath alag krna hoga
        //Atma nirbhar
        dp[u][1]+=black*dp[v][1];
        dp[u][1]%=mod;

    }
}

void solve()
{
    int n,x;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x;
        g[i].pb(x);
        g[x].pb(i);
    }
    fl(i,0,n) cin>>col[i];
    dfs(0);
    cout<<dp[0][1]<<endl;
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
