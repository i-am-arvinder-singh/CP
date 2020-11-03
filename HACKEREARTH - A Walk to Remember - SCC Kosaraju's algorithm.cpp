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
#define RIGHT(x)        2*x+2

const double pi = acos(-1.0);

class Kosaraju{
    vector<vector<int>> edges;
    vector<vector<int>> rev;
    stack<int> myStack;
    vector<bool> vis;
    int n;
public:
    Kosaraju(vector<vector<int>> edges, int n){
        this->edges = edges;
        this->n = n;
        vis = vector<bool> (n+2,false);
        rev = vector<vector<int>> (n+2);
    }

    vector<vector<int>> findSCC(){
        for(int i=1;i<=n;i++){
            if(!vis[i]) dfs(i);
        }
        fill(vis.begin(),vis.end(),false);
        reverse();
        vector<vector<int>> ans;
        while(!myStack.empty()){
            int cur = myStack.top();
            myStack.pop();
            if(!vis[cur]){
                vector<int> temp;
                dfsAlpha(cur,temp);
                ans.pb(temp);
            }
        }
        return ans;
    }

    void dfs(int node){
        vis[node] = true;
        for(auto next : edges[node]){
            if(vis[next]==false){
                dfs(next);
            }
        }
        myStack.push(node);
    }

    void reverse(){
        for(int i=1;i<=n;i++){
            for(auto next : edges[i]){
                rev[next].pb(i);
            }
        }
    }

    void dfsAlpha(int node, vector<int> &v){
        vis[node] = true;
        v.pb(node);
        for(auto next:rev[node]){
            if(!vis[next]) dfsAlpha(next,v);
        }
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n+2);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
    }
    Kosaraju K(edges,n);
    vector<vector<int>> ans = K.findSCC();
    vector<int> res(n+2,0);
    for(auto vec:ans){
        if((int)vec.size()<=1) continue;
        for(auto ele:vec){
            res[ele] = 1;
        }
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<endl;
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