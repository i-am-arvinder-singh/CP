#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

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

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n,m;

string s[60];
bool vis[55][55];

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool valid(int i, int j)
{
    return i>=1 && i<=n && j>=1 && j<=m;
}

void solve()
{
    cin>>n>>m;
    fl(i,1,n+1){
        cin>>s[i];
        s[i]='0'+s[i];
//        cout<<s[i]<<endl;
    }
    fl(i,1,n+1)
        fl(j,1,m+1){
            if(s[i][j]=='B'){
                fl(k,0,4){
                    int i_ = i+dir[k][0];
                    int j_ = j+dir[k][1];
                    if(valid(i_,j_)&&s[i_][j_]=='.')
                        s[i_][j_]='#';
                }
            }
        }
    queue<pii> q;
    memset(vis,0,sizeof(vis));
    if(s[n][m]=='.'){
        q.push({n,m});
        vis[n][m]=true;
    }
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        fl(k,0,4){
            int i_ = cur.ff+dir[k][0];
            int j_ = cur.ss+dir[k][1];
            if(valid(i_,j_)&&!vis[i_][j_]&&s[i_][j_]!='#'){
                q.push({i_,j_});
                vis[i_][j_]=true;
            }
        }
    }
    bool ok = true;
    fl(i,1,n+1)
        fl(j,1,m+1)
            if((s[i][j]=='G'&&!vis[i][j]) || (s[i][j]=='B'&&vis[i][j])) {
                ok = false;
                break;
            }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
	omniphantom
	w(t) solve();
	return 0;
}
