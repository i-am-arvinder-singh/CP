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

ini mx = 5e3+5;
int n,m,k;
int delay[mx],a[mx],b[mx],c[mx];
int dp[mx][mx];
vi g[mx];//To track most valuable fort

int f(int i, int army)
{
    if(army<a[i]) return -inf; //if army is less than required to defeat
    if(i>n) return 0;
    if(dp[i][army]!=-1) return dp[i][army];
    int ans = f(i+1,army+b[i]);//Recruit and move onto next
    //Above is without claiming and moving forward
    int sum = 0;
    fl(j,0,g[i].size()){//here we start to claim
        //We just find which works better
        sum+=g[i][j];
        if((army+b[i])>=(j+1))
            ans=max(ans,sum+f(i+1,army+b[i]-(j+1)));
    }
    return dp[i][army]=ans;
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    fl(i,1,n+1){
        delay[i]=i;
        cin>>a[i]>>b[i]>>c[i];
    }
    fl(i,1,m+1){
        int u,v;
        cin>>u>>v;
        delay[v]=max(delay[v],u);
    }
    fl(i,1,n+1) g[delay[i]].pb(c[i]);
    fl(i,1,n+1) sort(g[i].begin(),g[i].end(),greater<int>());
    int ans = f(1,k);//Initial fort followed by army
    if(ans<0) ans=-1;
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
