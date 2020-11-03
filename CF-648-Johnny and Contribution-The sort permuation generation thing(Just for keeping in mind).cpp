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

ini mx = 5e5 +5;
vi g[mx];
int t[mx],vis[mx];

void solve()
{
    int n,m;
    cin>>n>>m;
    fl(i,0,m){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    fl(i,1,n+1) cin>>t[i];
    fl(i,1,n+1){
        set<int> s;
        for(auto u:g[i]){
            if(t[u]<t[i]) s.insert(t[u]);
            if(t[u]==t[i]){
                cout<<-1<<endl;
                return;
            }
        }
        if(s.size()!=t[i]-1){
            cout<<-1<<endl;
            return;
        }
    }
    pii a[n+1];
    fl(i,1,n+1){
        a[i].ff=t[i];
        a[i].ss=i;
    }
    sort(a+1,a+n+1);
    fl(i,1,n+1) cout<<a[i].ss<<" ";
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
