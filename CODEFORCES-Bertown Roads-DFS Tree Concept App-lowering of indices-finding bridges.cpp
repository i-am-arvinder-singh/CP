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

ini mx = 1e5 + 5;
vi g[mx];
int vis[mx],tin[mx],low[mx];
int timer;
bool check;
vt(pii) p;

void dfs(int n, int par)
{
    vis[n]=1;
    tin[n]=low[n]=timer++;
    for(auto x: g[n]){
        if(x==par) continue;
        if(vis[x]){//There could be multiple paths from the node n to its ancestor we take the one lies farthest away from that node
            low[n]=min(low[n],tin[x]);
            if(tin[x]<tin[n])
                p.pb({n,x});
        }
        else{
            dfs(x,n);
            if(low[x]>tin[n]){
                check = true;
                return;
            }
            low[n]=min(low[n],low[x]);
            p.pb({n,x});
        }
    }
}

int32_t main()
{
	fio;
	int n,m;
	cin>>n>>m;
	fl(i,0,m){
	    int a,b;
	    cin>>a>>b;
	    g[a].pb(b);
	    g[b].pb(a);
	}
	dfs(1,-1);
	if(check) cout<<0<<endl;
    else{
        fl(i,0,p.size()){
            cout<<p[i].ff<<" "<<p[i].ss<<endl;
        }
    }
	return 0;
}
