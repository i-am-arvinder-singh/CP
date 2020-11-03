#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

//#define endl            "\n"
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

ini mx = 2e5+5;
int a[mx],b[mx];
bool vis[mx]={};
vi v;

void dfs(int x)
{
    vis[x]=true;
    if(b[x]!=-1 && !vis[b[x]]) dfs(b[x]);
    v.pb(x);//After the call to maintain order
}

void solve()
{
    int n;
    cin>>n;
    fl(i,1,n+1) cin>>a[i];
    fl(i,1,n+1) cin>>b[i];
    fl(i,1,n+1) if(!vis[i]) dfs(i);
    vi neg,show;
    neg.clear();
    show.clear();
    int ans = 0;
    bfl(i,v.size(),0){
        int id = v[i];
        if(a[id]<0){
            neg.pb(id);
            continue;
        }
        ans+=a[id];
        if(b[id]!=-1) a[b[id]]+=a[id];
        show.pb(id);
    }
//    cout<<"**** "<<neg.size()<<endl;
    for(int i = (int)neg.size()-1;i>=0;i--){
//        cout<<"HEY"<<endl;
        int id = neg[i];
        ans+=a[id];
        show.pb(id);
    }
    cout<<ans<<endl;
    for(auto val : show) cout<<val<<" ";
}

int32_t main()
{
	omniphantom
	#if 0
	w(t)
	#endif // 1
    solve();
	return 0;
}
