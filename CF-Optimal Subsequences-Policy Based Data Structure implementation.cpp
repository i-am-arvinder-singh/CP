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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n;
    cin>>n;

    vi a(n);
    vt(pii) b;

    fl(i,0,n){
        cin>>a[i];
        b.pb({-a[i],i});//in-order to sort the given array in non increasing order you can always insert negative elements to do so since the input elements are positive
    }

    sort(b.begin(),b.end());

    int m;
    cin>>m;
    vector<pair<pii,int>> req(m);

    fl(i,0,m){
        cin>>req[i].ff.ff>>req[i].ff.ss;
        req[i].ss = i;
    }

    sort(req.begin(),req.end());

    vi ans(m);

    ordered_set pos;

    int len = 0;

    fl(i,0,m){
        while(len < req[i].ff.ff) pos.insert(b[len++].ss);
        //Now we require kth smallest element (we do -1 to k in brackets)
        ans[req[i].ss] = a[*pos.find_by_order(req[i].ff.ss-1)];
    }

    for(auto x:ans) cout<<x<<endl;
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
