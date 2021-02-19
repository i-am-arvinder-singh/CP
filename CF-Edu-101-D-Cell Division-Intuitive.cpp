#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
// using namespace __gnu_pbds;

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

void solve()
{	
	int n;
	cin>>n;
	int cnt = 0;
	vector<pii> ans;
	if(n>=16){
		for(int i=1;i<=n;i++) if(!(i==1 || i==2 || i==4 || i==16 || i==n)) ans.pb({i,n});
		int val = n;
		if(n!=16){
			while(val!=1){
				val=(val+15)/16;
				ans.pb({n,16});
			}
		}
		for(int i=0;i<2;i++){
			ans.pb({16,4});
		}
		for(int i=0;i<2;i++){
			ans.pb({4,2});
		}
	}
	else if(4<=n && n<16){
		for(int i=1;i<=n;i++) if(!(i==1 || i==2 || i==4 || i==n)) ans.pb({i,n});
		int val = n;
		if(n!=4){
			while(val!=1){
				val=(val+3)/4;
				ans.pb({n,4});
			}
		}
		for(int i=0;i<2;i++){
			ans.pb({4,2});
		}
	}
	else if(2<=n && n<4){
		for(int i=1;i<=n;i++) if(!(i==1 || i==2 ||i==n)) ans.pb({i,n});
		int val = n;
		while(val!=1){
			val=(val+1)/2;
			ans.pb({n,2});
		}
	}
	cout<<ans.size()<<endl;
	for(auto &[x,y]:ans) cout<<x<<" "<<y<<endl;
}	

int32_t main()
{
	omniphantom
	#if 1
	w(t)
	#endif // 0
    solve();
	return 0;
}