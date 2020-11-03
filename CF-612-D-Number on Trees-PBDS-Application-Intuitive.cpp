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

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini mx = 2e3+4;
vi g[mx];
int root;
int a[mx];

ordered_set pos;
int c[mx],tin[mx],tout[mx];
int cnt = 0;

void __dfs(int u, int p)
{
    tin[u]=cnt++;
    for(auto x:g[u]){
        if(x==p) continue;
        __dfs(x,u);
    }
    tout[u]=cnt;
}

bool dfs(int u, int p)
{
    a[u]= *pos.find_by_order(c[u]);
    bool check = true;
    if(c[u]>=(tout[u]-tin[u])) check = false;
    pos.erase(a[u]);
    for(auto v:g[u]){
        if(v==p) continue;
        check=(check && dfs(v,u));
    }
    return check;
}

void solve()
{
    int n;
    cin>>n;
    fl(i,1,n+1){
        int x;
        cin>>x>>c[i];
        g[i].pb(x);
        g[x].pb(i);
        if(x==0) root = i;
        pos.insert(i);
    }
    __dfs(root,0);
    if(dfs(root,0)){
        cout<<"YES"<<endl;
        fl(i,1,n+1) cout<<a[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
