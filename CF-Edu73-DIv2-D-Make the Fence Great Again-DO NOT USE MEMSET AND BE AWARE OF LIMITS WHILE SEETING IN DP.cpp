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
#define ppii            pair<int,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini mx = 3e5 + 5;
int a[mx], b[mx],dp[mx][3];
int n;

int f(int i, int prev_inc)
{
    if(dp[i][prev_inc]!=-1) return dp[i][prev_inc];
    if(i==n) return 0;
    int ans = inf;
    for(int inc = 0; inc<=2; inc++){
        if(i==0) ans=min(ans,f(i+1,inc)+inc*b[i]);
        else if(i!=0 && (a[i-1]+prev_inc != a[i]+inc)){
            ans=min(ans,f(i+1,inc)+inc*b[i]);
        }
    }
    return dp[i][prev_inc]=ans;
}

void solve()
{
    //DO NOT USE MEMSET
    //BE CAREFUL ABOUT LIMITS WHILE SETTING INITIAL VALUES IN DP
    cin>>n;
    fl(i,0,n) cin>>a[i]>>b[i];
    fl(i,0,n+1) dp[i][0]=dp[i][1]=dp[i][2]=-1;
    cout<<f(0,0)<<endl;
}

int32_t main()
{
	omniphantom
    w(t) solve();
	return 0;
}
