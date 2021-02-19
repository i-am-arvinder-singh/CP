#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
#define ll              long long
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=(int)a; i<(int)b; i++)
#define bfl(i,a,b)      for(int i=(int)a-1; i>=(int)b; i--)
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
// #define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)        2*x+2
#define all             xs,ys,xf,yf,c6,c1,c5,c2

const double pi = acos(-1.0);

int n,m,k;
int dp[72][72][72][37];

int f(int row, int col, int mod, int left, vector<vector<int>> &v){
    if(dp[row][col][mod][left]!=-1) return dp[row][col][mod][left];
    if(row==n-1 && (!left || col==m)) return dp[row][col][mod][left] = mod==0?0:-inf;
    if(col==m || !left) return dp[row][col][mod][left] = f(row+1,0,mod,m/2,v);
    int ans = -inf;//We had to initialize by -inf because in the end in case of ot returns -inf on
    // upper calls in the recursion (tree) there could be loss on the information of this -inf indicator 
    // when answer here i.e., ans is initialized with 0
    if(left) ans=max(ans,v[row][col]+f(row,col+1,(mod+v[row][col])%k,left-1,v));
    ans=max(ans,f(row,col+1,mod,left,v));
    return dp[row][col][mod][left] = ans;
}

void solve()
{
    cin>>n>>m>>k;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<max(0ll,f(0,0,0,m/2,v));
}   

int32_t main()
{
	omniphantom
	#if 0
	w(t)
	#endif // 0
    solve();
	return 0;
}