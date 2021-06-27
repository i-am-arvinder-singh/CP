#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

//#define endl            "\n"
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
#define you_can_do_it     ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
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
//#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x
#define RIGHT(x)        2*x+1
#define all(v)            v.begin(),v.end()
#define rall(v)            v.rbegin(),v.rend()

const double pi = acos(-1.0);

#define PRINT(x)        {print(x); return;}
#define FOR(v)            fl(i,0,(int)v.size())   read(v[i]);
#define FOR1(v)            fl(i,1,(int)v.size()+1) read(v[i]);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<endl;}


//void err(istream_iterator<string> it) {}
//template<typename T, typename... Args>
//void err(istream_iterator<string> it, T a, Args... args) {
//    cerr << *it << " = " << a << "  , ";
//    err(++it, args...);
//}
//
//template<typename... T>
//void print(T...args){
//    ((cout<<args<<" "),...);
//}
//
//template<typename... T>
//void read(T&...args){
//    ((cin>>args),...);
//}

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

/*

Credits : owen_up

SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x - 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit

*/


//1,2 ,3  ,4,  ,5     ,6      ,7       ,8        ,9         ,10 digit prime
//1,11,101,1187, 11489, 109229, 1000003, 10000019, 100000007, 1000000007
//1,13,127,1009, 10007, 100003, 1000033, 10000079, 100000037, 1000000009


void solve(int tc)
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> ones,zeros;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        if(v[i]==1) ones.pb(i);
        else        zeros.pb(i);
    }
    n = ones.size();
    int m = zeros.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    std::function<int(int,int)> f = [&](int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        if(i<n && j==m) return dp[i][j] = (int)inf;
        if(i==n) return dp[i][j] = 0ll;
        return dp[i][j] = min(f(i+1,j+1) + abs(ones[i]-zeros[j]),f(i,j+1));
    };
    int ans = f(0,0);
    cout<<ans<<endl;

}

int32_t main()
{
    you_can_do_it
    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}
