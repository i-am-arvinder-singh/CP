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
#define mod             998244353
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
    
const int MAX = 2e5+5;
int value[MAX],level[MAX];
int entryTimeAtNode[MAX], exitTimeAtNode[MAX];
vector<int> g[MAX];

int timer;

class BIT{
private:
    int n;
    vector<int> BIT_Tree;
public:
    BIT(int n) : n(n), BIT_Tree(n+1,0) {}

    void add(int id, int val){
        for(;id<=n;id+=(id&-id)){
            BIT_Tree[id] += val;
        }
    }

    int sum(int id){
        int ans = 0;
        for(;id;id-=(id&-id)){
            ans += BIT_Tree[id];
        }
        return ans;
    }

};

void dfs(int node , int par, int levl)
{
    level[node] = levl;
    entryTimeAtNode[node]  = timer;
    timer++;
    for(auto child : g[node]){
        if(child!=par){
            dfs(child,node,levl+1);
        }
    }
    exitTimeAtNode[node]  = timer;
    timer++;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>value[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    timer = 1;
    dfs(1,-1,0);
    BIT bit(2*n+1);
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int id, val;
            cin>>id>>val;
            if((level[id]&1)) val=-val;
            bit.add(entryTimeAtNode[id]+1,val);
            bit.add(exitTimeAtNode[id]+1,-val);
        }
        else{
            int id;
            cin>>id;
            cout<<value[id] + bit.sum(exitTimeAtNode[id])*((level[id]&1)?-1:1)<<endl;
        }
    }
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

