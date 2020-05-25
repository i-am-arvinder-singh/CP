#include<bits/stdc++.h>
using namespace std;

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

void solve()
{
    int n;
    cin>>n;
    int a[n+1],dp[n+1];
    fl(i,1,n+1) cin>>a[i],dp[i]=1;
    int ans = 1;
    for(int i=2;i<=n;i++){
        int mx = 0;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                int d1=j;
                int d2=i/j;
                if(a[i]>a[d2]){
                    mx=max(dp[d2],mx);
                }
                if(a[i]>a[d1]){
                    mx=max(dp[d1],mx);
                }
            }
        }
        dp[i]+=mx;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
	w(t) solve();
	return 0;
}
