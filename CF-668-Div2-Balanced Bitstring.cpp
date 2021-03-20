#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS
                           //To avoid writing __gnu_pbds:: <function_type> for pbds

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

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool f = true;
    for(int i=0;i<k;i++){
        set<char> w;
        for(int j=i;j<n;j+=k) w.insert(s[j]);
        if(w.find('0')!=w.end() && w.find('1')!=w.end()){
            f = false;
            break;
        }
        if(w.find('0')!=w.end()) for(int j=i;j<n;j+=k) s[j] = '0';
        if(w.find('1')!=w.end()) for(int j=i;j<n;j+=k) s[j] = '1';
    }
    int cnt0 = 0, cnt1 = 0;
    for(int i=0;i<k;i++){
        if(s[i]=='0') cnt0++;
        if(s[i]=='1') cnt1++;
    }
    if(cnt0>k/2 || cnt1>k/2) f = false;
    cout<<(f?"YES":"NO")<<endl;
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

