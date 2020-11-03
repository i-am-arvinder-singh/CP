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
 
struct comp{
    bool operator() (const pair<int, int> &f1, const pair<int, int> &f2){
        return f1.ff<f2.ff;
    }
};
 
void solve()
{
     int n,m,q;
     cin>>n>>m>>q;
     vector< pair<pair<int,int>,int> > v(m);
     vector<pair<int,int>> g[n];
     for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
        g[b].pb({a,c});
     }
    int a;
    while(q--){
        cin>>a;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int>> > pq;
        pq.push({0ll,a});
        vi dist(n,inf);
        dist[a]=0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            for(auto p:g[cur.ss]){
                if(cur.ff+p.ss<dist[p.ff]){
                    dist[p.ff]=cur.ff+p.ss;
                    pq.push({dist[p.ff],p.ff});
                }
            }
        }
        int cnt = 0;
        int big = -1;
        for(int i = 0; i < n; i ++){
            if(dist[i] == inf)
                continue;
            if(dist[i] == big){
                cnt ++;
            }
            else if(dist[i] > big){
                big = dist[i];
                cnt = 1;
            }
        }
        cout<<big<<" "<<cnt<<endl;
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