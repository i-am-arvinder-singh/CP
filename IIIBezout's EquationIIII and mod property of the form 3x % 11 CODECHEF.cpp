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
//#define mod             100000000
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

ini mx = 1e5+5;
vi g[mx],leaf;
int m[mx], gcd[mx];

void clean()
{
    fl(i,0,mx){
        g[i].clear();
        m[i]=gcd[i]=0;
    }
    leaf.clear();
}

void dfs(int node, int par)
{
    bool flag=true;
    for(auto child: g[node]){
        if(child!=par){
            flag=false;
            gcd[child] = __gcd(gcd[child],gcd[node]);
            dfs(child,node);
        }
    }
    if(flag) leaf.pb(node);
}

void solve()
{
    clean();
    int n;
    cin>>n;
    fl(i,0,n-1){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    fl(i,1,n+1) cin>>gcd[i];
    fl(i,1,n+1) cin>>m[i];
    dfs(1,-1);
    sort(leaf.begin(),leaf.end());
    for(auto ans:leaf){
        int mod = m[ans];
        int x = __gcd(mod,gcd[ans]);

        cout<< ((mod/x)-1)*x <<" ";
    }
    cout<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
