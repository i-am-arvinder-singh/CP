#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

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
    int n;
    cin>>n;
    vector<int> v(n),d(n);
    for(int i=0;i<n;i++) cin>>v[i];
    d[0] = v[0];
    for(int i=1;i<n;i++) d[i] = v[i] - v[i-1];
    int sum = 0;
    for(int i=0;i<n;i++) if(i==0 || d[i]>0) sum+=d[i];
    cout<<((sum + 1)>>1)<<endl;//ceil of half the sum
    auto add = [&](int id, int val){
        if(id==0 || d[id]>0) sum-=d[id];
        d[id]+=val;
        if(id==0 || d[id]>0) sum+=d[id]; 
    };
    int q;
    cin>>q;
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        l--;
        add(l,x);
        if(r<n) add(r,-x);
        cout<<((sum + 1)>>1)<<endl;
    }
    //There is a funndamental difference between
    // (a+b)>>1ll;
    // and (a+b)/2;
    //This question helps in understanding that.
}

int32_t main()
{
	omniphantom
	#if 0
	w(t)
	#endif // 0
    solve();
	return 0;
}

