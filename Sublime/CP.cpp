#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define inf 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define LEFT(x) 2*x+1
#define RIGHT(x) 2*x+2
#define rall(v) v.rbegin(),v.rend()

const double PI = acos(-1.0);

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/

/*

Credits : owen_up
 
SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x - 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit

1,2 ,3  ,4,  ,5     ,6      ,7       ,8        ,9         ,10 digit prime
1,11,101,1187, 11489, 109229, 1000003, 10000019, 100000007, 1000000007
1,13,127,1009, 10007, 100003, 1000033, 10000079, 100000037, 1000000009
 
*/

vector<int> z_(string &s){
    int n = s.length();
    vector<int> z(n);
    for(int i=0,l=0,r=0;i<n;i++){
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
            z[i]++;
        if(z[i]+i-1>r)
            l=i,r=z[i]+i-1;
    }
    return z;
}

long long lcm_(long long x, long long y)
{
	x%=MOD;
	y%=MOD;
    long long ans =  ((long long)(x)*(long long)(y))/(__gcd(x,y));
    return ans%MOD;
}

int mul(int x, int y)
{
    x%=MOD;
    y%=MOD;
    long long ans = (long long)x * (long long)y;
    return ans%MOD;
}

int solve_(vector<string> &A)  {
    int n = A.size();
    vector<int> tt;
    for(int i=0;i<n;i++){
        string a;
        for(int j=0;j<A[i].size();j++)
            a+=A[i][j];
        int t = a.length();
        a=a+a;
        vector<int> z = z_(a);
        int id = 0;
        long long cnt = 1;
        int q = 0;
        int w = a.length();
        for(int time=2;time<=w;time++){
            if(z[(id+cnt)%t]>=t || (id+cnt)%t==0){
            	q=time-1;
                break;
            }
            cnt+=time;
        }
        tt.push_back(q);
    }
    long long ans = 1;

    unordered_map<int,int> my;
    for(int i=0;i<n;i++){
        int temp1 = tt[i];
        debug(tt[i]);
        unordered_map<int,int> w;
        for(int j=2;j*j<=tt[i];j++){
            while((temp1%j)==0){
                temp1/=j;
                w[j]++;
            }
        }
        if(temp1>1){
            w[temp1]++;
        }
        for(auto &[key,val]:w){
            my[key]=max(my[key],val);
        }
    }
    for(auto &[x,y]:my){
        int temp = y;
        while(temp--){
            ans=mul(ans,x);
        }
    }
    return ans;

}


void solve(int tc) {
   	vector<string> A =   { "a", "abaabaaba", "aba" };
   	int ans = solve_(A);
   	cout<<ans<<endl;
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
		
	fastio();
	auto start1 = high_resolution_clock::now();
	int tc = 1;
	// cin>>tc;
	for(int i=1;i<=tc;i++){
		solve(i);
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);

	#ifndef ONLINE_JUDGE
		cerr << "Time: " << duration . count() / 1000 << endl;
	#endif
}