#include<bits/stdc++.h>
using namespace std;

//#define endl            "\n"
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              insert
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
//#define mod             100000000
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

ini mx = 1e5 + 5;
set<int> g[mx];//In vector we don't have erase
int n,m,timer,x,y,vis[mx],in[mx],low[mx];
set<pii> bridges;

void clean()
{
    fl(i,0,mx){
        g[i].clear();
        vis[i]=in[i]=low[i]=0;
    }
    timer=0;
    bridges.clear();
}

void dfs(int node, int par=-1)
{
    vis[node] = 1;
    in[node]=low[node]=timer++;
    for(auto child:g[node]){
        if(child==par) continue;
        if(vis[child]){
            low[node]=min(low[node],low[child]);//
        }
        else{
            dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>in[node]) bridges.pb({node,child});
        }
    }
}

void cydfs(int node)
{
    vis[node]=1;
    for(auto child:g[node]) if(!vis[child]) cydfs(child);
}

bool hascycle(int node, int par=-1)
{
    vis[node]=1;
    for(auto child:g[node]){
        if(child!=par){
            if(vis[child]) return true;
            if(hascycle(child,node)) return true;
        }
    }
    return false;
}

void solve()
{
    clean();
    cin>>n>>m;
    fl(i,0,m){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    //All the bridges in the graph is found using the following algorithm
    fl(i,1,n+1) if(!vis[i]) dfs(i);

    //Bridges are removed from the graph structure
    for(auto e:bridges){
        g[e.ff].erase(e.ss);
        g[e.ss].erase(e.ff);
    }

    //Clear visited array prepare for another dfs
    fl(i,0,n+1) vis[i]=0;

    //counting CC with cycles
    int cyclecnt=0;
    fl(i,1,n+1) if(g[i].size()>0 && !vis[i]) cydfs(i),cyclecnt++;

    if(cyclecnt!=1){
        cout<<-1<<endl;
    }
    else{
        int mxdeg=0;
        int resnode=inf;//We later minimize this value it's our answer

        //finding node with highest degree
        fl(i,1,n+1) if(g[i].size()>mxdeg) mxdeg=g[i].size(),resnode=i;

        //Remove all the edges of the highest degree node we selected
        fl(i,1,n+1) g[i].erase(resnode),vis[i]=0;
        g[resnode].clear();

        //checking if no cycle is existing after removal
        //Also, always the node with the highest degree is the candidate for failure point
        fl(i,1,n+1){
            if(!vis[i] && hascycle(i)){
                //cycle found!
                //no failure!
                resnode=-1;
                break;
            }
        }
        cout<<resnode<<endl;
    }
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
