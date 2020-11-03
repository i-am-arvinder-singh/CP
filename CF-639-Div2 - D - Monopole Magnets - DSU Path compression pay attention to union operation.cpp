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

ini mx = 1e6+5;
int p[mx];

int f(int a)
{
    if(p[a]<=0) return a;
    return p[a] = f(p[a]);//Like dp // path compression
}

void u(int a, int b)
{
    p[a]+=p[b];
    p[b]=a;
}

int n,m;

int code(int i, int j)
{
    return m*i+j;
}

void solve()
{
   cin>>n>>m;
   string s[n];
   fl(i,0,n) cin>>s[i];
   set<int> row,col;
   vi aw_row, aw_col;
   fl(i,0,n){
       bool found_black = false;
       fl(j,0,m){
           if(s[i][j]=='#'){
                row.insert(i),col.insert(j);
                found_black = true;
           }
       }
        if(!found_black) aw_row.pb(i);
   }
   fl(j,0,m){
       bool found_black = false;
       fl(i,0,n){
           if(s[i][j]=='#'){
                found_black = true;
                break;
           }
       }
        if(!found_black) aw_col.pb(j);
   }
   fl(i,0,aw_row.size()){
       fl(j,0,aw_col.size()){
           row.insert(aw_row[i]),col.insert(aw_col[j]);
       }
   }
   if(row.size()<n || col.size()<m){
       cout<<-1<<endl;
       return;
   }
   //Further checks allows us to check for multiple segments
   //Checks will be applied for both the rows and the cols
   bool ok = true;
   fl(i,0,n){
       vi v;
       fl(j,0,m) if(s[i][j]=='#') v.pb(j);
       fl(i,1,v.size())
            if(v[i]>v[i-1]+1){
                ok = false;
                break;
            }
   }

   fl(j,0,m){
       vi v;
       fl(i,0,n) if(s[i][j]=='#') v.pb(i);
       fl(i,1,v.size())
            if(v[i]>v[i-1]+1){
                ok = false;
                break;
            }
   }

   if(!ok){
       cout<<-1<<endl;
       return;
   }
   //we are sure at this point that the answer exists
   fl(i,0,m*n+2){
        p[i]=-i;
   }

   fl(i,0,n){
       fl(j,0,m){
           if(s[i][j]=='.') continue;
           if(i+1<n && s[i+1][j]=='#'){
                int a = f(code(i,j));
                int b = f(code(i+1,j));
                if(a!=b)
                u(a,b);
           }
           if(i-1>=0 && s[i-1][j]=='#'){
                int a = f(code(i,j));
                int b = f(code(i-1,j));
                if(a!=b)
                u(a,b);
           }
           if(j+1<m && s[i][j+1]=='#'){
                int a = f(code(i,j));
                int b = f(code(i,j+1));
                if(a!=b)
                u(a,b);
           }
           if(j-1>=0 && s[i][j-1]=='#'){
                int a = f(code(i,j));
                int b = f(code(i,j-1));
                if(a!=b)
                u(a,b);
           }
       }
   }
   int ans = 0;
   fl(i,0,n){
       fl(j,0,m){
           if(s[i][j]=='.') continue;
           int nn = code(i,j);
           if(f(nn)==nn) ans++;
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
