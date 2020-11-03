#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define ff              first
#define ss              second
#define int             long long
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
//#define pqb             priority_queue<int>
//#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define PARENT(n) (n/2)

ini mx = 2e5+5;
vi edges[mx];
int level[mx],vis[mx],sub[mx],leaf[mx],parent[mx];
int cnt=0;
priority_queue< pii > Q;

void dfs(int u, int p, int x)
{
    int f=0;
    level[u]=x;//Information for level
    int in=cnt++;
    for(auto v:edges[u]){
        if(v==p) continue;
        parent[v]=u;
//        cout<<v<<" "<<u<<endl;
        vis[u]++;//Information for children
        dfs(v,u,x+1);
        f=1;
    }
    int out=cnt;
    sub[u]=out-in;//Information for nodes in the subtree
    if(f==0)
        Q.push({level[u],u});
}

int32_t main()
{
	fio;
	int n,k;
	cin>>n>>k;
	fl(i,1,n){
	    int a,b;
	    cin>>a>>b;
	    a--;b--;
	    edges[a].pb(b);
	    edges[b].pb(a);
	}
	dfs(0,-1,0);
//	cout<<endl;
//	for(int i=0;i<n;i++) cout<<sub[i]<<" ";
//	cout<<endl;
	int ans=0;
//	cout<<endl;
	while(k && !Q.empty()){
        pii node = Q.top();
//        cout<<node.first<<" "<<node.second<<endl;
        Q.pop();
        ans+=node.first;
        //It may seem that we are adding levels
        //but is not the  case
        //we are adding something that if in case that
        // node is encountered then this quantity will get added
//        cout<<"addend : "<<node.first<<endl;
        int p = parent[node.second];
        vis[parent[node.second]]--;
//    	cout<<endl;
//    	for(int i=0;i<n;i++) cout<<vis[i]<<" ";
//    	cout<<endl;
        if(vis[p]==0){
            Q.push({level[p]-sub[p]+1,p});
//            cout<<"CHECK: "<<level[p]-sub[p]<<" "<<sub[p]<<" "<<p<<endl;
        }
        k--;
	}
	cout<<ans<<endl;
	return 0;
}
