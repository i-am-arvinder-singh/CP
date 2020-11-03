#include<bits/stdc++.h>
using namespace std;

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
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

ini mx=1e4+5;
vi g[mx];
int n,m,vis[mx],dis[mx];

void clean(int n)
{
    fl(i,0,n+1){
        vis[i]=0;
        dis[i]=0;
        g[i].clear();
    }
}

void bfs(int w)
{
    vis[w]=1;
    queue<int> q;
    q.push(w);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto v:g[node]){
            if(!vis[v]){
                dis[v]=dis[node]+1;
                vis[v]=1;
                q.push(v);
                if(v==n)
                    return;
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    clean(n);
    fl(i,0,m){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    bfs(1);
    cout<<dis[n]<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
