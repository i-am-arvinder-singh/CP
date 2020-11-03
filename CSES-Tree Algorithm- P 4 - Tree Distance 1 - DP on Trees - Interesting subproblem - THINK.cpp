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
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)         2*x+2
 
const double pi = acos(-1.0);
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
class dpOnTrees{
    vector<vector<int>> edges;
    vector<vector<int>> dp;
    vector<int> depth;
    vector<int> ans;
    int n, dia;
public:
    dpOnTrees(vector<vector<int>> edges, int n){
        this->edges = edges;
        this->n = n;
        depth = vector<int> (n+2);
        ans   = vector<int> (n+2,0);
    }
 
    void solve(){
        depthDfs(1,-1); 
        solve(1,-1,-1);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }   
 
    int depthDfs(int node, int par){
        int ans = 0;
        for(auto child : edges[node]){
            if(child==par) continue;
            ans = max(ans,1+depthDfs(child,node));
        }
        return depth[node] = ans;
    }
 
    void solve(int node, int par, int par_ans){
 
        vector<int> pref,suff;
        for(auto child:edges[node]){
            if(child==par) continue;
            pref.pb(depth[child]);
            suff.pb(depth[child]);
        }
        for(int i=1;i<(int)pref.size();i++) pref[i] = max(pref[i-1] , pref[i]);
        for(int i=(int)suff.size()-2;i>=0;i--) suff[i] = max(suff[i+1] , suff[i]);
 
        int c_cnt = 0;
        for(auto child:edges[node]){
            if(child==par) continue;
            int left  = (c_cnt==0) ? -inf : pref[c_cnt-1];
            int right = (c_cnt==(int)pref.size()-1) ? -inf : suff[c_cnt+1];
            int top   = par_ans + 1;
            solve(child,node,max({left+1,right+1,top}));
            c_cnt++;
        }
        ans[node] = max({ans[node], (pref.empty()?0:pref.back()+1), par_ans+1});
    }
};
 
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> edges(n+2);
    for(int i=2;i<=n;i++){
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    dpOnTrees t(edges,n);
    t.solve();
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