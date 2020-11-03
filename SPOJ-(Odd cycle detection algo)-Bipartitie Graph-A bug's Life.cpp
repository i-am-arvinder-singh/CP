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

ini mx = 1e6+5;
vi g[mx];
int vis[mx],col[mx];

bool dfs(int node, int c)
{
    vis[node]=1;
    col[node]=c;

    for(auto v:g[node]){
        if(!vis[v]){
            if(dfs(v,c^1)==false)
                return false;
        }
        else//If the child is marked
            if(col[v]==col[node])
                return false;
    }
    return true;
}

void clean(int n)
{
    fl(i,0,n+1){
        g[i].clear();
        vis[i]=0;
        col[i]=0;
    }
}

int cnt=0;

void solve()
{
	int n,a,b,m;
	cin>>n>>m;
	fl(i,0,m){
	    cin>>a>>b;
	    g[a].pb(b);
	    g[b].pb(a);
	}
	fl(i,1,n+1){
	    if(!vis[i]){
            if(dfs(i,0)==false){
                cout<<"Scenario #"<<(++cnt)<<":\n";
                cout<<"Suspicious bugs found!\n";
                clean(n);
                return;
            }
	    }
	}
	cout<<"Scenario #"<<(++cnt)<<":\n";
	cout<<"No suspicious bugs found!\n";
	clean(n);
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
