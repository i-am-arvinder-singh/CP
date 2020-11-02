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
#define inf             1e18+1000
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)        2*x+2
#define MAX_SIZE        100003

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}

void solve()
{
    int r,n;
    cin>>r>>n;
    int t[n+3]={},x[n+3]={},y[n+3]={},dp[n+3]={},smax[n+3]={};
    t[0]=0,x[0]=1,y[0]=1;
    for(int i=1;i<=n;i++) cin>>t[i]>>x[i]>>y[i];
    for(int i=n;i>=0;i--){
        int cur = 0;
        int j = i+1;
        while(j<=n){
            if(abs(t[i]-t[j])>2*r) break;
            int dis = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            if(dis<=abs(t[i]-t[j])) amax(cur,dp[j]+1);
            j++;
        }
        amax(cur,smax[j]+1);
        dp[i]=cur;
        smax[i]=max(smax[i+1],dp[i]);
    }   
    cout<<dp[0]-1<<endl;
    //Since we assumed that at (1,1) we had a celebrity but this is not the case.
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

