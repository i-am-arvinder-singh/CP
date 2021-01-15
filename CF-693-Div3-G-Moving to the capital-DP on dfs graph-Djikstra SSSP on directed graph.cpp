#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
// using namespace __gnu_pbds;

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
#define all(v)			v.begin(),v.end()

const double pi = acos(-1.0); 

#define PRINT(x)		{print(x); return;}
#define FOR(v)			fl(i,0,(int)v.size())   read(v[i]);
#define FOR1(v)			fl(i,1,(int)v.size()+1) read(v[i]);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<endl;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "  , ";
	err(++it, args...);
}

template<typename... T>
void print(T...args){
	((cout<<args<<" "),...);
}

template<typename... T>
void read(T&...args){
	((cin>>args),...);
}

/////// \|/ \|/ Credits: okwedook for template below \|/ \|/ ////////
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.ff >> p.ss; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
/////////////////////////////////////////////////////////////////////


class Dijsktra {
    using ptype = pair<int,int>;
    int n;
    vector<int> vis;
public:
    vector<vector<ptype>> edges;
    vector<int> dist;
    Dijsktra(int n){
        this->n = n;
        dist  = vector<int> (n);
        vis   = vector<int> (n);
        edges = vector<vector<ptype>> (n);
    }

    void addEdge(int a, int b, int weight){
        edges[a].pb({b,weight});
    }

    void run(int src) {
        fill(dist.begin(),dist.end(),inf);
        fill(vis.begin(),vis.end(),0);
        priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int cur = t.ss;
            if(vis[cur]) continue;
            vis[cur] = 1;
            dist[cur]=min(dist[cur],t.ff);
            for(auto next:edges[cur]){
                pq.push({dist[cur]+next.ss,next.ff});
            }
        }
    }
};



void solve()
{	
	
	int n, m;
	read(n,m);
	Dijsktra d(n);
	for(int i=0;i<m;i++){
		int x,y;
		read(x,y);
		x--,y--;
		d.addEdge(x,y,1);
	}
	d.run(0);
	vector<int> ans(n,inf);
	vector<vector<int>> dp(n);
	for(int i=0;i<n;i++){
		dp[i] = vector<int> (2,-1);
	}
	std::function<int(int,int,int)> dfs = [&](int node, int p, int can){
		int res = d.dist[node];
		if(res==0) return dp[node][can] = 0ll;
		if(dp[node][can]!=-1) return dp[node][can];
		for(int i=0;i<d.edges[node].size();i++){
			int child = d.edges[node][i].ff;
			if(can && d.dist[child]<=d.dist[node]){
				res=min(res,dfs(child,node,0));
			}
			else if(d.dist[child]>d.dist[node]){
				res=min(res,dfs(child,node,can));
			}
		}
		return dp[node][can] = res;
	};
	for(int i=0;i<n;i++) ans[i] = min(dfs(i,-1,0),dfs(i,-1,1));
	for(auto ele:ans) cout<<ele<<" ";
	cout<<endl;
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