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
#define mod             998244353
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


//1
//100 1 11
//1 1
//1 1
//1 1
//2 2
//2 100
//1 2
//2 3
//3 4
//5 6
//6 100
//4 5
//100

void solve()
{
    int n,x,m;
    cin>>n>>x>>m;
    vector<pii> v;
    fl(i,0,m){
        int x,y;
        cin>>x>>y;
        v.pb({x,y});
    }
//    sort(v.begin(),v.end());
    int ta=v[0].ff, tb=v[0].ss;
    int val=1;
    bool ok = false;
    fl(i,0,v.size()){
        if(ok){
            if( (tb>=v[i].ff && tb<=v[i].ss) ||(v[i].ff<=ta && ta<=v[i].ss)){
                tb=max(tb,v[i].ss);
                ta=min(ta,v[i].ff);
                val = tb-ta+1;
            }
        }
        if(v[i].ff<=x && x<=v[i].ss && !ok){
            ta=v[i].ff;
            tb=v[i].ss;
            val = tb-ta+1;
            ok = true;
        }
    }
    cout<<val<<endl;
}

int32_t main()
{
	omniphantom
	w(t) solve();
	return 0;
}
