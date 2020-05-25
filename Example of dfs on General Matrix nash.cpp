#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define ff              first
#define int             long long
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define fio          ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define PARENT(n) (n/2)

ini mx = 1e3+5;
int x[mx][mx],y[mx][mx],vis[mx][mx],cnt=0;
char ans[mx][mx];

void dfs(int u, int v)
{
    // no need to worry about boundary conditions as it is buffered
    // by zeros
    cnt++;
    vis[u][v]=1;
    if(x[u+1][v]==x[u][v] && y[u+1][v]==x[u][v] && vis[u+1][v]!=1){
        ans[u+1][v]='U';
        dfs(u+1,v);
    }
    else if(x[u-1][v]==x[u][v] && y[u-1][v]==x[u][v] && vis[u-1][v]!=1){
        ans[u-1][v]='D';
        dfs(u-1,v);
    }
    else if(x[u][v+1]==x[u][v] && y[u][v+1]==x[u][v] && vis[u][v+1]!=1){
        ans[u][v+1]='L';
        dfs(u,v+1);
    }
    else if(x[u][v-1]==x[u][v] && y[u][v-1]==x[u][v] && vis[u][v-1]!=1){
        ans[u][v-1]='R';
        dfs(u,v-1);
    }
}

int32_t main()
{
	fio;
	int i,j;
	cin>>n;
	vt(pii) block, iinf;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>x[i][j]>>y[i][j];
            if(x[i][j]==i && y[i][j]==j)
                block.pb({i,j});
            else if(x[i][j]==-1 && y[i][j]==-1)
                iinf.pb({i,j});
        }
    }
    for(auto i : block){
        if(!vis[i.first][i.second]){
            ans[i.first][i.second]='X';
            dfs(i.first,i.second);
        }
    }
    for(auto i : iinf){
        if(!vis[i.first][i.second]){
            dfs(i.first,second);
            int u=i.first, v=i.second;
            if()
        }
    }
	return 0;
}
