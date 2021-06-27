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
#define rall(v)			v.rbegin(),v.rend()

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

/////// \|/ \|/ Credits: okwedook for template below \|/ \|/ ////////
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.ff >> p.ss; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
/////////////////////////////////////////////////////////////////////


const int MAX = 2e7+10;
vector<int> sieve(MAX,-1);
vector<int> primes(MAX,0);
vector<bool> is_prime(MAX,1);

int factors(int n){
	vector<int> temp;
	int val = 0;
	while(sieve[n]!=-1){
		temp.pb(sieve[n]);
		int sv = sieve[n];
		while(n%sv==0) n/=sv;
		val++;
	}
	return val;
}

void SPF(){

	for(int i=2;i<MAX;i++){
		if(sieve[i]!=-1) continue;
		for(int j=i;j<MAX;j+=i) if(sieve[j]==-1) {
			sieve[j]=i;
		}
	}

	primes[1] = 0;

	// for(int i=2;i<MAX;i++){
	// 	int t = i/sieve[i];
	// 	primes[i] = primes[t] + (sieve[i]!=sieve[t]);
	// }

	for(int i=2;i<MAX;i++){
		if(is_prime[i]){
			primes[i]++;
			for(int j=2*i;j<MAX;j+=i){
				is_prime[j]=0;
				primes[j]++;
			}
		}
	}

	// for(int i=2;i<MAX;i++){
	// 	primes[i]=factors(i);
	// }

}

void solve()
{
    int c,d,x;
    cin>>c>>d>>x;
    int ans = 0;
    for(int i=1;i*i<=x;i++){
		if(x%i) continue;
		int t = x/i + d;
        if(t%c==0) {
			t/=c;
			// cout<<"********* "<<t<<" "<<primes[t]<<endl;
			ans+=(1ll<<primes[t]);
		}
		if(i*i==x) continue;
		int i_ = x/i;
		t = x/i_ + d;
		if(t%c==0){
			t/=c;
			// cout<<"********* "<<t<<" "<<primes[t]<<endl;
			ans+=(1ll<<primes[t]);
		}
    }
    // for(auto &ele:facts_of_x){
    //     int t = x/ele + d;
    //     if(t%c) continue;
    //     t/=c;
	// 	// cout<<"********* "<<t<<" "<<primes[t]<<endl;
    //     ans+=(1ll<<primes[t]);
    // }
    cout<<ans<<endl;

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
