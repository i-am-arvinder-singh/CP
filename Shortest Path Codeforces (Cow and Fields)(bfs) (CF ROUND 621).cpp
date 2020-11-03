#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
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
#define PARENT(n) (n/2)

ini mx=2e5+5;
vi g[mx];
int a[mx],d[2][mx];
int n,m,k;

void bfs()
{
    memset(d,-1,sizeof(d));
    queue<int> q;
    q.push(1);
    d[0][1]=0;//Counting distance from first node
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(d[0][v]==-1){//If that vertex is not marked
                d[0][v]=d[0][u]+1;
                q.push(v);
            }
        }
    }
    q.push(n);
    d[1][n]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(d[1][v]==-1){
                d[1][v]=d[1][u]+1;
                q.push(v);
            }
        }
    }
}

int32_t main()
{
	fio;
	cin>>n>>m>>k;
	fl(i,0,k) cin>>a[i];//Special Fields
	while(m--){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
	}
	bfs();
	int ans=0;
	vt(pii) p;
	fl(i,0,k)
	    p.pb({d[0][a[i]],d[1][a[i]]});
    sort(p.begin(),p.end());
    fl(i,0,k-1)
        ans=max(ans,p[i].first+p[i+1].second+1);//maximizing considering the maximized value to be minimum which might not very well be the case
    ans=min(ans,d[1][1]);
    cout<<ans<<endl;
	return 0;
}
