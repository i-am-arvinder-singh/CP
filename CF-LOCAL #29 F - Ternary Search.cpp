#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
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

ini mx = 1e5 +5;
int n, k;
vi v(mx);

int f(int x)
{
    int l = x, r = x+k, cost =0;
    for(int i=0;i<n;i++){
        if(l<=v[i] && v[i]<=r) continue;
        if(v[i]>r) cost+= v[i]-r;
        else if(v[i]<l) cost += l-v[i];
    }
    return cost;
}


void solve()
{
    cin >> n >> k;
    for( int i=0 ; i<n ; i++ ) cin>>v[i];
    int l = *min_element(v.begin(),v.begin()+n);
    int r = *max_element(v.begin(),v.begin()+n);
    while(r-l>2){
         int ll = l + (r-l)/3, rr = r - (r-l)/3;
         int c1 = f(ll) , c2 = f(rr);
         if(c1<c2) r = rr;
         else      l = ll;
    }
    int ans = f(l);
    for(int i=l+1;i<=r;i++) ans = min(ans,f(i));
    cout<<ans<<endl;
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
