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
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n],cnt[2*k+1]={},pref[2*k+2]={};
    fl(i,0,n) cin>>a[i];
    fl(i,0,n/2) cnt[a[i]+a[n-i-1]]++;
    fl(i,0,n/2){
        int l=min(a[i],a[n-i-1])+1;
        int r=max(a[i],a[n-i-1])+k;
        pref[l]++;
        pref[r+1]--;
    }
    fl(i,2,2*k+2) pref[i]+=pref[i-1];
    int ans=inf;
    fl(i,2,2*k+1) ans=min(ans,(pref[i]-cnt[i])+(n/2-pref[i])*2);
    cout<<ans<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
