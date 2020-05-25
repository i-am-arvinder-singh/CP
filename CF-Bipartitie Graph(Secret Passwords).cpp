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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

ini N = 1e6;

vi edges[N];
int vis[N];

void addEdge(int a, int b)
{
    edges[a].pb(b);
    edges[b].pb(a);
}

void dfs(int i)
{
    vis[i]=1;
    for(auto child : edges[i]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

void solve()
{
    int n;
    cin>>n;

    fl(i,0,n){
        string s;
        cin>>s;
        for(char c:s){
            addEdge(i,n+c-'a');
        }
    }
    int ans = 0;
    for(int i=n;i<n+26;i++){
        if(!edges[i].empty() && !vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
