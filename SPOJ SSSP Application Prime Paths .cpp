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

ini mx=1e5+5;
vi g[mx];
int n,m,vis[mx],dis[mx],primes[mx];
vi p;

void sieve()
{
    fl(i,2,mx) primes[i]=1;
    fl(i,2,mx){
        if(primes[i]){
            for(int j=2*i;j<mx;j+=i)
                primes[j]=0;
        }
    }
    fl(i,1000,10000){
        if(primes[i])
        p.pb(i);
    }
}

bool isValid(int i, int j)
{
    int cnt=0;
    while(i>0){
        if(i%10 != j%10) cnt++;
        i/=10;
        j/=10;
    }
    if(cnt==1) return true;
    else return false;
}

void buildGraph()
{
    fl(i,0,p.size()){
        fl(j,i+1,p.size()){
            if(isValid(p[i],p[j])){
                g[p[i]].pb(p[j]);
                g[p[j]].pb(p[i]);
            }
        }
    }
}

void clean(int n)
{
    fl(i,0,n){
        vis[i]=0;
        dis[i]=0;
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
    clean(mx);
    int a;
    cin>>a>>n;
    bfs(a);
    cout<<dis[n]<<endl;
}

int32_t main()
{
	fio;
	sieve();
	buildGraph();
	w(t) solve();
	return 0;
}
