#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS
                           //To avoid writing __gnu_pbds:: <function_type> for pbds

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

ini MAX = 1e5+5;
vi g[MAX];
int dis[MAX];

void dfs(int node, int p=-1)
{
    for(auto ch:g[node]){
        if(ch!=p){
            dis[ch]=dis[node]+1;
            dfs(ch,node);
        }
    }
}

void solve()
{
    int n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;
    for(int i=0;i<=n;i++){
        g[i].clear();
        dis[i]=0;
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(a);
    int dis_ab = dis[b];
    int id = 0;
    for(int j=1;j<=n;j++) if(dis[id]<dis[j]) id=j;
    for(int j=0;j<=n;j++) dis[j]=0;
    dfs(id);
    id = 0;
    for(int j=1;j<=n;j++) if(dis[j]>dis[id]) id=j;
    int dia = dis[id];
    da=min(da,dia),db=min(db,dia);
    if(dis_ab<=da || db<=2*da) cout<<"Alice"<<endl;
    else                       cout<<"Bob"<<endl;
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

