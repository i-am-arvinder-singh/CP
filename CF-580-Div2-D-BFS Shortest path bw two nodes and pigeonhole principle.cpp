#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

//#define endl            "\n"
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
#define ppii            pair<int,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini mx = 200;
vi g[mx];
int bfs(int x, int y)
{
    queue<pii> q;
    bool vis[mx]={};
    vis[x]=true;
    for(auto v:g[x]){
        if(v==y) continue;//Because it was the immediate edge
        q.push({v,1});
//        vis[j]=true;
    }
    while(!q.empty()){
        auto p = q.front();
        if(p.ff==y) return p.ss;//Not true for immediate edge
        q.pop();
        vis[p.ff] = true;//mark
        for(auto v:g[p.ff]){
            if(vis[v]) continue;
            q.push({v,p.ss+1});
        }
    }
    return inf;
}

int solve()
{
    int n;
    cin>>n;
    vi v(n);
    int cnt = 0;
    fl(i,0,n) cin>>v[i],cnt+=(v[i]>0);
    //Use pigeonhole principle.
    if(cnt>120) return cout<<3,0;
    vi a;
    fl(i,0,n) if(v[i]>0) a.pb(v[i]);
    n = a.size();
    fl(i,0,n) fl(j,i+1,n){
        int z = (a[i]&a[j]);
        if(z) g[i].pb(j),g[j].pb(i);
    }
    int ans = inf;
    fl(i,0,n){
        for(auto j:g[i]){
            ans=min(ans,bfs(i,j)+1);
        }
    }
    if(ans==inf) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
