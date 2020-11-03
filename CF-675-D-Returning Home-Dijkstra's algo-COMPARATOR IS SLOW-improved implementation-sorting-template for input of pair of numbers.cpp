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
    int n,m;
    cin>>n>>m;
    int sx,sy,fx,fy;
    cin>>sx>>sy>>fx>>fy;
    using ptype = pair<pii,int>;
    vector<ptype> p;
    for(int i=0;i<m;i++){
        pii w;
        cin>>w;
        p.pb({w,i});
    }
    p.pb({{sx,sy},m});
    p.pb({{fx,fy},m+1});
    // m   -> start index
    // m+1 -> end index
    Dijsktra d(m+2);
    d.addEdge(m,m+1,abs(sx-fx)+abs(sy-fy));
    for(int i=0;i<m;i++){
        d.addEdge(m,i,min (abs(sx-p[i].ff.ff),abs(sy-p[i].ff.ss)));
        d.addEdge(i,m+1,abs(fx-p[i].ff.ff)+abs(fy-p[i].ff.ss));
    }
    sort(p.begin(),p.begin()+m,[&](auto p1, auto p2){
        return p1.ff.ff < p2.ff.ff;
    });
    for(int i=0;i<m;i++){
        if(i>0)   d.addEdge(p[i].ss,p[i-1].ss,abs(p[i].ff.ff-p[i-1].ff.ff));
        if(i+1<m) d.addEdge(p[i].ss,p[i+1].ss,abs(p[i].ff.ff-p[i+1].ff.ff));
    }
    sort(p.begin(),p.begin()+m,[&](auto p1, auto p2){
        return p1.ff.ss< p2.ff.ss;
    });
    for(int i=0;i<m;i++){
        if(i>0)   d.addEdge(p[i].ss,p[i-1].ss,abs(p[i].ff.ss-p[i-1].ff.ss));
        if(i+1<m) d.addEdge(p[i].ss,p[i+1].ss,abs(p[i].ff.ss-p[i+1].ff.ss));
    }
    d.run(m);
    cout<<d.dist[m+1]<<endl;
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