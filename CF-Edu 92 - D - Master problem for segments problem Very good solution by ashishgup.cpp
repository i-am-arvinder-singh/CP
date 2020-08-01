#include<bits/stdc++.h>
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

int solve()
{
    //Credits:AshishGup
    //for this amazing solution
    //Reduces the cumbersome hassle
    //of making cases
    int n,k,l1,r1,l2,r2;
    cin>>n>>k;
    cin>>l1>>r1>>l2>>r2;
    if(l1>l2) swap(l1,l2), swap(r1,r2);
    int inter = max(0ll,min(r1,r2)-l2);
    int val = inter;
    val*=n;
    k-=val;
    int ans = 0;
    if(k<=0) return cout<<0<<endl,0;
    for(int i=1;i<=n;i++){
        if(k==0) break;
        int reqd = min(k,max(r1,r2)-min(l1,l2)-inter);
        int cost = max(0ll,l2-r1)+reqd;
        if(i>=2) cost = min(cost,reqd*2);
        ans+=cost;
        k-=reqd;
    }
    if(k>0) ans+=(k*2);
    cout<<ans<<endl;
    return 0;
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
