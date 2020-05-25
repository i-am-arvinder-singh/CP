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
//#define mod             100000000
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
    int n,x;
    cin>>n;
    set<int> s;
    fl(i,0,n){
        cin>>x;
        s.insert(x);
    }
    int a[s.size()],j=0;
    for(auto i:s) a[j++]=i;
    n=s.size();
    if(n==1){
        cout<<2*a[0]<<endl;
        return;
    }
    int lgcd[n], rgcd[n];
    lgcd[0]=a[0];
    fl(i,1,n) lgcd[i]=__gcd(lgcd[i-1],a[i]);
    rgcd[n-1]=a[n-1];
    bfl(i,n-1,0) rgcd[i]=__gcd(rgcd[i+1],a[i]);
    int ans=0;
    ans=max(ans,rgcd[1]+a[0]);
    ans=max(ans,lgcd[n-2]+a[n-1]);
    fl(i,1,n-1) ans=max(ans,__gcd(lgcd[i-1],rgcd[i+1])+a[i]);
    cout<<ans<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
