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

int n,m,t;
void dfs(int n,int p, int d)
{
    for(auto v:g[n]){
        if(v!=p){
            dfs(v,n,d+1);
        }
    }
    if(d>m){
        m=d;
        t=n;
    }
}

int32_t main()
{
	fio;
	cin>>n;
	fl(i,0,n-1){
	    int a,b;
	    cin>>a>>b;
	    g[a].pb(b);
	    g[b].pb(a);
	}
	dfs(1,-1,0);
	m=0;
	dfs(t,-1,0);
	cout<<m<<endl;
	return 0;
}
