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

template<typename T1, typename T2> T1 amin(T1 &a, T2 b){if(b<a)a=b; return a;}
template<typename T1, typename T2> T1 amax(T1 &a, T2 b){if(b>a)a=b; return a;}

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct comp{
    bool operator() (const pair<int, int> &f1,const  pair<int, int> &f2){
        return (f1.ff-f1.ff/2)*f1.ss > (f2.ff-f2.ff/2)*f2.ss;
    }
};

ini mx = 1e5+5;
multiset<pair<int,int>,comp> s[3];
vector<pair<int,pii>> g[mx];
int sum = 0;

int dfs(int node, int p)
{
    int ans = 0;
    bool f = true;
    for(auto x:g[node]){
        if(x.ff==p) continue;
        f = false;
        int tmp = dfs(x.ff,node);
        s[x.ss.ss].insert({x.ss.ff,tmp});
        sum += tmp*x.ss.ff;
        ans += tmp;
    }
    if(f) return 1;
    return ans;
}

void clean(int n)
{
    s[1].clear();
    s[2].clear();
    sum=0;
    for(int i=1;i<=n;i++) g[i].clear();
}

void solve()
{
    int n,w;
    cin>>n>>w;
    clean(n);
    for(int i=2;i<=n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        g[a].pb({b,{c,d}});
        g[b].pb({a,{c,d}});
    }
    dfs(1,-1);
    vector<int> m[3];
    for(int i=1;i<=2;i++){
        int val = 0;
        while(s[i].size()){
            auto tmp = *s[i].begin();
            s[i].erase(s[i].begin());
            val += (tmp.ff - tmp.ff/2)* tmp.ss;
            tmp.ff /= 2;
            if(tmp.ff) s[i].insert(tmp);
            m[i].pb(val);
        }
    }
    int req = sum-w;
    if(req<=0){
        cout<<0<<endl;
        return;
    }
    int x,y=sz(m[2])-1;
    int ans = inf;
    for(x=0;x<sz(m[1]);x++){
        if(m[1][x]>=req) amin(ans,x+1);
        while(m[1][x]+m[2][y-1]>=req && (y-1)>=0) y--;
        if(y>=0 && m[1][x]+m[2][y]>=req){
            amin(ans,(x+1)+2*(y+1));
        }
    }
    for(y=0;y<sz(m[2]);y++){
        if(m[2][y]>=req) amin(ans,2*(y+1));
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
