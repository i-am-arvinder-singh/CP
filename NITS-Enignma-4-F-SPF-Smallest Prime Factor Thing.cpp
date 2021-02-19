#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

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
#define all(v)			v.begin(),v.end()

const double pi = acos(-1.0); 

#define PRINT(x)		{print(x); return;}
#define FOR(v)			fl(i,0,(int)v.size())   read(v[i]);
#define FOR1(v)			fl(i,1,(int)v.size()+1) read(v[i]);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<endl;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "  , ";
	err(++it, args...);
}

template<typename... T>
void print(T...args){
	((cout<<args<<" "),...);
}

template<typename... T>
void read(T&...args){
	((cin>>args),...);
}

int MAX = 1e6+10;
vector<int> sieve(MAX,-1);

void SPF(){
	for(int i=2;i<MAX;i++){
		if(sieve[i]!=-1) continue;
		for(int j=i;j<MAX;j+=i) if(sieve[j]==-1) sieve[j]=i;
	}
}

vector<int> factors(int n){
	vector<int> temp;
	while(sieve[n]!=-1){
		temp.pb(sieve[n]);
		n=sieve[n];
	}
	return temp;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	int cnt = 0;
	unordered_map<int,int> my;
	for(int i=0;i<n;i++){
		map<int,int> w;
		while(v[i]!=1){
			w[sieve[v[i]]]++;
			v[i]/=sieve[v[i]];
		}
		for(auto ele:w) my[ele.ff]=max(my[ele.ff],ele.ss);
	}
	for(auto ele:my) cnt+=ele.ss;
	if(cnt&1) cout<<"Eren"<<endl;
	else	  cout<<"Mikasa"<<endl;
}	

int32_t main()
{
	omniphantom
	SPF();
	#if 1
	w(t)
	#endif // 0
    solve();
	return 0;
}
 