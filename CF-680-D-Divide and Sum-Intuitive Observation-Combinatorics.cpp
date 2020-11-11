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
#define mod             998244353 
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
#define RIGHT(x)        2*x+2

const double pi = acos(-1.0);

int power(int x, int y){
	int ans = 1;
	while(y){
		if(y&1) ans*=x;
		ans%=mod;
		x*=x;
		x%=mod;
		y>>=1;
	}
	return ans;
}

int inverse(int x){
	return (power(x,mod-2))%mod;
}

int mul(int x, int y){
	x%=mod;
	y%=mod;
	return (x*y)%mod;
}

void solve()
{
	int n;
	cin>>n;
	int MAX = 2*n+10;
	int fact[MAX],inv[MAX];
	fact[0]=fact[1]=1;
	inv[0]=inverse(fact[0]);
	inv[1]=inverse(fact[1]);
	for(int i=2;i<MAX;i++){
		fact[i]=i*fact[i-1];
		fact[i]%=mod;
		inv[i]=inverse(fact[i]);
	}
	vector<int> v(2*n);
	for(int i=0;i<2*n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	int bigSum = 0, smallSum = 0;
	for(int i=0;i<n;i++){
		smallSum+=v[i];
		smallSum%=mod;
	}
	for(int i=n;i<2*n;i++){
		bigSum+=v[i];
		bigSum%=mod;
	}
	int ans = (bigSum - smallSum + mod)%mod;
	ans=mul(ans,
		mul(fact[2*n],
			mul(inv[n],inv[n])
		)
	);
	cout<<ans<<endl;
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
