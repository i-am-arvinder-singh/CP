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

ini N = 2e5 +5;
pii a[N];
int n,s;

bool ok(int mid)
{
    int sum = 0;
    int cnt = 0;
    vi v;
    for(int i = 0;i < n; i++){
        if(a[i].ss<mid){
            sum+=a[i].ff;//Do the minimum salary
        }
        else if (a[i].ff>=mid){
            sum+=a[i].ff;//Again do the minimum salary
            cnt++;
        }
        else
            v.pb(a[i].ff);
    }
    int need = max(0ll, (n+1)/2-cnt);

    if(need>v.size()) return false;

    for(int i = 0; i<v.size(); i++){
        if(i<(v.size()-need)) sum+=v[i];
        else sum+=mid;
    }
    return sum<=s;
}

void solve()
{
    cin>>n>>s;
    fl(i,0,n) cin>>a[i].ff>>a[i].ss;
    sort(a,a+n);
    int l = 1, r = 1e9+5;
    int mid;
    while(r-l>1){
        mid = (l+r)>>1ll;
        if(ok(mid)) l = mid;
        else r = mid;
    }
    cout<<l<<endl;
}

int32_t main()
{
	omniphantom
    w(t) solve();
	return 0;
}
