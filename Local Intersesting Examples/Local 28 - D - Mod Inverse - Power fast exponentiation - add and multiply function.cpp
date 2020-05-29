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

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini N = 1e5 +5;
int fact[N]={};

int power(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x%mod;
        y = y>>1;
        x = x*x % mod;
    }
    return res%mod;
}

int inv(int n)
{
    return power(n,mod-2)%mod;
}

void precompute()
{
    fact[1]=1;
    fact[0]=1;
    for(int i=2;i<=N;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
}

int C(int n, int r)
{
    if(n==r || r==0) return 1;
    if(r>n) return 0;
    int ans = fact[n];
    ans = (ans*inv(fact[r]))%mod;
    ans = (ans*inv(fact[n-r]))%mod;
    return ans;
}

void solve()
{
   precompute();
   int n;
   cin>>n;
   string s;
   cin>>s;
   int m = count(s.begin(),s.end(),'m');
   int e = count(s.begin(),s.end(),'e');
   int o = count(s.begin(),s.end(),'o');
   int w = count(s.begin(),s.end(),'w');
   int a[e+2]={}, b[o+2]={};
   for(int i=1;i<=e;i++){
       a[i]=C(e,i);
   }
   for(int i=1;i<=e;i++){
       a[i]+=a[i-1];
       a[i]%=mod;
   }
   for(int i=1;i<=o;i++){
       b[i]=C(o,i);
   }
   int ans = 0;
   for(int i=1;i<=o;i++){
       int bb = b[i];
       int j;
       if(e>i){
           j = a[e]-a[i];
           j%=mod;
       }
       else j=0;
       bb*=(j);
       bb%=mod;
       ans+=bb;
       ans%=mod;
   }
   int ww1,ww2;
   ww1=(power(2,m)+mod-1)%mod;
   ww2=(power(2,w)+mod-1)%mod;
   int ww = (ww1*ww2)%mod;
   ans = (ww*ans)%mod;
   cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
