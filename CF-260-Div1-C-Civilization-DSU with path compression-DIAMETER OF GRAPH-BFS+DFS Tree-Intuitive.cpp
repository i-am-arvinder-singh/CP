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
#define BIT             1

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> g[n+2];
    vector<int> p(n+2);
    for(int i=1;i<=n;i++){
        p[i]=-i;
    }

    std::function<int(int)> f =  [&](int a)
    {
        if(p[a]<0) return a;
        return p[a] = f(p[a]);//Like dp // path compression
    };

    std::function<int(int,int)> u = [&](int a, int b)
    {
        a=f(a),b=f(b);
        if(a==b) return -1;
        p[b]=a;
        return 1;
    };

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        u(a,b);
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> dia(n+2,0),vis(n+2,0),dis(n+2,inf);
    vector<int> nodes;

    std::function<void(int)> dfs = [&](int node){
        nodes.pb(node);
        vis[node] = 1;
        for(auto child:g[node]){
            if(vis[child]) continue;
            dfs(child);
        }
    };

    auto bfs = [&](int node){
        dfs(node);
        for(auto node : nodes) vis[node] = 0;
        vis[node] = 1;
        dis[node] = 0;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto child:g[cur]){
                if(dis[child]<dis[cur] && vis[child]) continue;
                dis[child] = dis[cur] + 1;
                vis[child] = 1;
                q.push(child);
            }
        }
        int temp_id = -1; 
        int mx = -1;
        for(auto node : nodes){
            if(dis[node]>mx){
                mx = dis[node];
                temp_id = node;
            }
        }
        node = temp_id;
        for(auto node : nodes) vis[node] = 0;
        vis[node] = 1;
        dis[node] = 0;
        while(!q.empty()) q.pop();
        q.push(node);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto child:g[cur]){
                if(dis[child]<dis[cur] && vis[child]) continue;
                dis[child] = dis[cur] + 1;
                vis[child] = 1;
                q.push(child);
            }
        }
        mx = 0;
        for(auto node : nodes){
            if(dis[node]>mx){
                mx = dis[node];
            }
        }
        for(auto node : nodes){
            dia[node] = mx;
        }
    };
    map<int,int> my;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            nodes.clear();
            bfs(i);
        }
        my[f(i)] = dia[i];
    }

    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            int x;
            cin>>x;
            cout<<my[f(x)]<<endl;
        }
        else{
            int x,y;
            cin>>x>>y;
            if(x==y) continue;
            else{
                int px = f(x), py = f(y);
                int val = u(x,y);
                if(val==-1) continue;
                int newd = max({my[px],my[py],(my[px]+1)/2+(my[py]+1)/2+1});
                my[px]=newd;
                my[py]=newd;
            }
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

