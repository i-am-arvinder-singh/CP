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


void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

//    int ans_even = inf;
    int mn_even = inf;
    int sum_even = 0;

//    int ans_odd = inf;
    int mn_odd = inf;
    int sum_odd = 0;

    vector<int> dp1(n),dp2(n);
    int cnt_even =0, cnt_odd=0;

    for(int i=0;i<n;i++){
        if(i&1){
            cnt_odd++;
            sum_odd+=v[i];
            mn_odd=min(mn_odd,v[i]);
            int temp = sum_odd - mn_odd;
            temp += (mn_odd*(n-cnt_odd+1));
            dp1[i]=temp;
        }
        else{
            cnt_even++;
            sum_even+=v[i];
            mn_even=min(mn_even,v[i]);
            int temp = sum_even - mn_even;
            temp += (mn_even*(n-cnt_even+1));
            dp2[i]=temp;
        }
    }
    int res = inf;
    for(int i=1;i<n;i+=2){
        res=min(res,dp1[i]+dp2[i-1]);
    }
    for(int i=1;i<n-1;i+=2){
        res=min(res,dp1[i]+dp2[i+1]);
    }
    cout<<res<<endl;



//        ll n,a,b,c,d,x,y,r,k,j,i;
//       cin>>n;
//       ll arr[n+1],dp[n+1]={0},dp1[n+1]={0};
//       for(i=0;i<n;i++)
//        cin>>arr[i];
//        int cnt_odd=0,mn_odd=inf,sum_odd=0;
//        int cnt_even=0,mn_even=inf,sum_even=0;
//       for(i=0;i<n;i++){
//            if(i&1){
//                cnt_odd++;
//                mn_odd=min(mn_odd,arr[i]);
//                sum_odd+=arr[i];
//                int temp = sum_odd - mn_odd + (arr[i]*(n-cnt_odd+1));
//                dp1[i]=temp;
//            }
//            else{
//                cnt_even++;
//                mn_even=min(mn_even,arr[i]);
//                sum_even+=arr[i];
//                int temp = sum_even - mn_even + (arr[i]*(n-cnt_even+1));
//                dp[i]=temp;
//            }
//       }
//
//       int res = inf;
//        for(int i=1;i<n;i+=2){
//            res=min(res,dp1[i]+dp[i-1]);
//        }
//        for(int i=1;i<n-1;i+=2){
//            res=min(res,dp1[i]+dp[i+1]);
//        }
//        cout<<res<<endl;

//    ll n,a,b,c,d,x,y,r,k,j,i;
//    cin>>n;
//    ll arr[n+1],dp[n+1]={0},dp1[n+1]={0};
//    for(i=1;i<=n;i++) cin>>arr[i];
//    int c_odd=0,r_odd=inf,x_odd=0,ans_odd=inf;
//    int c_even=0,r_even=inf,x_even=0,ans_even=inf;
//    for(i=1;i<=n;i++){
//        if(i&1){
//           c_odd++;
//           r_odd=min(r_odd,arr[i]);
//           x_odd=x_odd+arr[i];
//           ans_odd=min(ans_odd,(n-c_odd+1)*r_odd+(x_odd-r_odd));
//        }
//        else{
//           c_even++;
//           r_even=min(r_even,arr[i]);
//           x_even=x_even+arr[i];
//           ans_even=min(ans_even,(n-c_even+1)*r_even+(x_even-r_even));
//        }
//    }
//    cout<<ans_even + ans_odd<<endl;

//        ll n,a,b,c,d,x,y,r,k,j,i;
//       cin>>n;
//       ll arr[n+1],dp[n+1]={0},dp1[n+1]={0};
//       for(i=1;i<=n;i++)
//        cin>>arr[i];
//        c=0,r=inf,x=0;
//        int ans_odd=inf;
//        int ans_even=inf;
//       for(i=1;i<=n;i=i+2){
//           c++;
//           r=min(r,arr[i]);
//           x=x+arr[i];
//           ans_odd=min(ans_odd,(n-c+1)*r+(x-r));
//       }
//       d=inf;
//       c=0,r=inf,x=0;
//       for(i=2;i<=n;i=i+2){
//           c++;
//           r=min(r,arr[i]);
//           x=x+arr[i];
//           ans_even=min(ans_even,(n-c+1)*r+(x-r));
//       }
////       for(i=3;i<=n;i=i+2)
////        d=min(d,dp[i]+dp1[i-1]);
//       cout<<ans_even+ans_odd<<endl;


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
