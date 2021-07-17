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

/*

function f(string s)
    int n = s.length()
    vector<int> v(n)
    for(i=1,l=0,r=0;i<n;i++){
        if(i<=r)
            z[i]=min(r-i+1,z[i-l])
        while(z[i]+i<n && s[z[i]]==s[z[i]+i])
            z[i]++
        if(z[i]+i-1>r)
            l=i, r = z[i]+i-1
    }
    return v

*/


class segTree{
private:
    int n;  
    vector<int> seg; 
    vector<vector<int>> lazy; 
    int getMid(int x, int y){
        return x+(y-x)/2;
    }
    int fun(int x){
        return (x*(x+1))/2;
    }
public: 
    segTree(int n) : n(n), seg(4*n+1), lazy(4*n+1,{-2,-2,0}) {}

    void propagate(int segId, int segStart, int segEnd)
    {
        if(lazy[segId][0]!=-2 and lazy[segId][1]!=-2){
            int left = lazy[segId][0];
            int right = lazy[segId][1];
            int cnt = lazy[segId][2];
            seg[segId] += cnt*(fun(right)-fun(left));
            int t = (left+right)/2;
            lazy[segId] = {-2,-2,0};
            if(segStart!=segEnd){
                lazy[LEFT(segId)] = {left,t,cnt};
                lazy[RIGHT(segId)] = {t,right,cnt};
            }
        }
    }

    int init(int segStart, int segEnd, int segId)
    {
        if(segStart==segEnd){
            seg[segId] = 0;
            return seg[segId]; 
        }
        int mid = getMid(segStart,segEnd);
        seg[segId] = init(segStart,mid,LEFT(segId)) + init(mid+1,segEnd,RIGHT(segId));
        return seg[segId];
    }

    void Update(int segStart, int segEnd, int segId, int qStart, int qEnd, int val)
    {
        propagate(segId,segStart,segEnd);
        cout<<"----> "<<segStart<<" "<<segEnd<<" "<<qStart<<" "<<qEnd<<" "<<segId<<endl;
        if(qEnd < segStart || segEnd < qStart) return;
        if(qStart <= segStart && segEnd <= qEnd){
            int dis = segEnd - segStart;
            int left = segStart - qStart;
            int right = dis + left + 1;
            int cnt = 1;
            debug("########");
            debug(segStart);
            debug(segEnd);
            debug(left);
            debug(right);
            debug("########");
            if(segStart==segEnd){
                seg[segId] += cnt*(fun(right) - fun(left));
                return;
            }
            seg[segId] += cnt*(fun(right) - fun(left) );
            int t = (left+right)/2;
            // int l = lazy[LEFT(segId)][0], r = lazy[LEFT(segId)][1];
            int c = lazy[LEFT(segId)][2];
            lazy[LEFT(segId)] = {left,t,c+cnt};
            // l = lazy[LEFT(segId)][0], r = lazy[RIGHT(segId)][1];
            c = lazy[RIGHT(segId)][2];
            lazy[RIGHT(segId)] = {t,right,c+cnt};
            return;
        }
        int mid = getMid(segStart,segEnd);
        Update(segStart,mid,LEFT(segId),qStart,qEnd,val);
        Update(mid+1,segEnd,RIGHT(segId),qStart,qEnd,val);
        seg[segId] = seg[LEFT(segId)] + seg[RIGHT(segId)];
    }

    int query(int segStart, int segEnd, int segId, int qStart, int qEnd)
    {
        propagate(segId,segStart,segEnd);
        if(qEnd < segStart || segEnd < qStart) return 0;
        if(qStart <= segStart && segEnd <= qEnd){
            if(segStart==segEnd) return seg[segId];
            return seg[segId];
        }
        int mid = getMid(segStart,segEnd);
        return query(segStart,mid,LEFT(segId),qStart,qEnd) + query(mid+1,segEnd,RIGHT(segId),qStart,qEnd);
    }
};


void solve(int tc) {
   	int n_;
    cin>>n_;
    int q;
    cin>>q;
    int n = 8;
    int cnt = log2(n_)+1;
    n = 1<<cnt;
    debug(n);
    segTree s(n);
    s.init(0, n-1, 0);
    for(int i=0;i<q;i++){
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        s.Update(0, n-1, 0, x, y, 0);
        int val = s.query(0, n-1, 0, x, y);

    }
    vector<int> ans(n);
    for(int i=0;i<n_;i++){
        ans[i] = s.query(0, n-1, 0, i, i);
    }
    for(int i=0;i<n_;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
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