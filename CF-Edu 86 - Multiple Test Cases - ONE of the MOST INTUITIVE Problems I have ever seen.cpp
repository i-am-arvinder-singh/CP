#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
//#define int             long long
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

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n+1],c[k+1];
    fl(i,1,n+1) cin>>a[i];
    fl(i,1,k+1) cin>>c[i];
    sort(a+1,a+n+1,greater<int>());
//    cout<<endl;
//    fl(i,1,n+1) cout<<a[i]<<" ";
//    cout<<endl;
    int ans = 0, sum = 0;
    fl(i,1,n+1){
        sum++;
        ans=max(ans,(sum+c[a[i]]-1)/c[a[i]]);
//        cout<<" ***** "<<ans<<endl;
    }
    vi v[ans];
    cout<<ans<<endl;
    fl(i,1,n+1){
        v[(i-1)%ans].pb(a[i]);
    }
    for(auto x:v){
        cout<<x.size()<<" ";
        for(auto y:x) cout<<y<<" ";
        cout<<endl;
    }
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
