#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
//#define int             long long
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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini mx = 2e5+5;
vi g1[mx],g2[mx];
int vis[mx];
int cnt1=0, cnt2=0;

void dfs1(int node)
{
    vis[node]=1;
    cnt1++;
    for(auto v:g1[node]){
        if(!vis[v]) dfs1(v);
    }
}

void dfs2(int node)
{
    vis[node]=1;
    cnt2++;
    for(auto v:g2[node]){
        if(!vis[v]) dfs2(v);
    }
}

void solve()
{
    //Un-necessary use of long long can bring in TLE
    
    //Always multiply 1ll first in order to type cast in the beginning except 
    //at the end, if you do it at the end then it may result in WA
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    fl(i,0,n+1){
        g1[i].clear();
        g2[i].clear();
    }
    memset(vis,0,sizeof(vis));
    fl(i,0,m){
        int x,y;
        cin>>x>>y;
        if(x!=a && y!=a){
            g1[x].pb(y);
            g1[y].pb(x);
        }
        if(x!=b && y!=b){
            g2[x].pb(y);
            g2[y].pb(x);
        }
    }
    cnt1=0, cnt2=0;
    dfs1(b);
    memset(vis,0,sizeof(vis));
    dfs2(a);
    long long ans = 1ll*(n-cnt1-1)*(n-cnt2-1);
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
    w(t) solve();
	return 0;
}
