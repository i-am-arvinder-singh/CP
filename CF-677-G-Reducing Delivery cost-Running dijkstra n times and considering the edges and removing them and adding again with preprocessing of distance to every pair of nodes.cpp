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

template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}

class Dijsktra {
    using ptype = pair<int,int>;
    int n;
    vector<vector<ptype>> edges;
public:
    vector<int> dist;
    Dijsktra(int n){
        this->n = n;
        dist  = vector<int> (n);
        edges = vector<vector<ptype>> (n);
    }

    void addEdge(int a, int b, int weight){
        edges[a].pb({b,weight});
        edges[b].pb({a,weight});
    }

    void run(int src) {
        fill(dist.begin(),dist.end(),inf);
        priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int cur = t.ss;
            for(auto next:edges[cur]){
                if(dist[next.ff]>dist[cur]+next.ss){
                    dist[next.ff]=dist[cur]+next.ss;
                    pq.push({dist[next.ff],next.ff});
                }
            }
        }
    }
};

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    Dijsktra d(n);
    vector<pii> edges;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        edges.push_back({x,y});
        d.addEdge(x,y,w);
    }
    vector<vector<int>> distances(n);
    for(int i=0;i<n;i++){
        d.run(i);
        distances[i] = d.dist;
    }
    vector<pii> r(k);
    for(auto &[a,b]:r){
        cin>>a>>b;
        a--,b--;
    }
    int ans = inf;
    for(auto &[x,y]:edges){
        int temp = 0;
        for(auto &[a,b]:r){
            temp += min({distances[a][b],distances[a][x]+distances[y][b],distances[a][y]+distances[x][b]});
        }
        ans=min(ans,temp);
    }
    cout<<ans<<endl;
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