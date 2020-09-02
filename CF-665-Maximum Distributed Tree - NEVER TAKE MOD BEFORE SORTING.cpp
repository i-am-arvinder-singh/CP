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

//struct comp{
//    bool operator() (const pair<int, int> &f1, const pair<int, int> &f2){
//        return (f1.ff-f1.ff/2)*f1.ss > (f2.ff-f2.ff/2)*f2.ss;
//    }
//};

//int sum = 0;
//ini mx = 1e5 +5;

//vector<pair<int,int>> g[mx];
//multiset<pair<int,int>,comp> s;

//int power(int x, int y)
//{
//    int ans=1;
//    while(y){
//        if(y&1) ans*=x;
//        x*=x;
//        y>>=1;
//    }
//    return ans;
//}

const int MAX = 1e5+10;

int n;
vector<int> g[MAX];
vector<int> sum;
vector<int> res;

int add(int x, int y)
{
    return (x+y)%mod;
}

int mul(int x, int y)
{
    x%=mod;
    y%=mod;
    return (x*y)%mod;
}

void dfs(int u, int p=-1)
{
    sum[u]=1;
    for(auto ch:g[u]){
        if(ch==p) continue;
        dfs(ch,u);
        sum[u]+=sum[ch];
    }
    res.push_back(sum[u]*(n-sum[u]));
}

void solve()
{
    cin>>n;
    sum.clear();
    sum.resize(n+1);
    res.clear();
    for(int i=0;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int m;
    cin>>m;
    vector<int> p(m);
    for(int i=0;i<m;i++) cin>>p[i];
    while((int)p.size()<n-1) p.push_back(1);
    sort(p.begin(),p.end());
    while((int)p.size()>n-1){
        int x = p.back();p.pop_back();
        int y = p.back();p.pop_back();
        p.push_back((x*y)%mod);
    }
    dfs(1);
    //Never take mod before sorting
    sort(res.begin(),res.end());
    int ans = 0;
    for(int i=1;i<(int)res.size();i++){
        ans=add(ans,mul(res[i],p[i-1]));
    }
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


