#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini mx = 2e5+5;
vi edges[mx],col[2],s;
deque<int> cyc;
vt(pii) e;
int pos[mx];
bool ex[mx];

void dfs(int node)
{
    pos[node]=s.size();
    col[pos[node]%2].pb(node);
    s.pb(node);
    for(auto v:edges[node]){
        if(pos[v]==-1) dfs(v);
        else if(pos[node]-pos[v]>1 && pos[v]!=-1 && cyc.empty()){
            for(int i=pos[v];i<=pos[node];i++){
                cyc.pb(s[i]);
                ex[s[i]]=1;//mark
            }
            return;
        }
    }
    s.pop_back();
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    while(m--){
        int a,b;
        cin>>a>>b;
        edges[a].pb(b);
        edges[b].pb(a);
        e.pb({a,b});
    }
    memset(pos,-1,sizeof(pos));
    dfs(1);
    if(cyc.empty()){
        if(col[0].size()<col[1].size()) swap(col[0],col[1]);
        cout<<1<<endl;
        fl(i,0,(k+1)/2) cout<<col[0][i]<<" ";
    }
    else{
        for(auto p:e){
            if(ex[p.ff] && ex[p.ss] && abs(pos[p.ff]-pos[p.ss])>1){
                while(cyc.front()!=p.ff && cyc.front()!=p.ss){
                    ex[cyc.front()]=0;
                    cyc.pop_front();
                }
                while(cyc.back()!=p.ff && cyc.back()!=p.ss){
                    ex[cyc.back()]=0;
                    cyc.pop_back();
                }
            }
        }
        if(cyc.size()<=k){
            cout<<2<<endl<<cyc.size()<<endl;
            for(auto x:cyc) cout<<x<<" ";
        }
        else{
            cout<<1<<endl;
            fl(i,0,(k+1)/2){
                cout<<cyc[i*2]<<" ";
            }
        }
    }
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
