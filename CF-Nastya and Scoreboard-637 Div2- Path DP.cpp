#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
//#define int             long long
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

map<int,string> tost;
ini mx = 2e3+5;
int n,k;

string s[mx];

int dp[mx][mx][10];
int changes[mx][10];

string ans;

int isValid(string a, string b)
{
    int val = -1;
    int cnt = 0;
    for(int i=0;i<7;i++){
        if(a[i]>=b[i]) cnt+=(a[i]-b[i]);
        else return val;
    }
    return cnt;
}

int f(int i, int k, int num)
{
    if(i>(n-1) && k==0) return dp[i][k][num]=1;
    if(i>(n-1) && k>0) return dp[i][k][num]=0;
    if(k<0) return dp[i][k][num]=0;

    if(dp[i][k][num]!=-1) return dp[i][k][num];

    int t = 0;
    fl(j,0,10){
        int c = changes[i][j];
        if(c!=-1) t=max(t,f(i+1,k-c,j));//Tracker to ensure answer exists
//        cout<<j<<" "<<t<<" "<<c<<endl;
    }
    return dp[i][k][num] = t;
}

void findans(int i, int k)
{
    if(i>(n-1)) return;
    bfl(j,10,0){
        int t = changes[i][j];
//        cout<<" %% "<<" "<<i<<" "<<(k-t)<<" "<<t<<" "<<dp[i+1][k-t][j]<<endl;
        if((k-t)>=0 && t!=-1 && dp[i+1][k-t][j]==1){
            char c = '0'+j;
            ans+=c;
            return findans(i+1,k-t);
        }
    }
}

void solve()
{
   cin>>n>>k;

   tost[0]="1110111";
   tost[1]="0010010";
   tost[2]="1011101";
   tost[3]="1011011";
   tost[4]="0111010";
   tost[5]="1101011";
   tost[6]="1101111";
   tost[7]="1010010";
   tost[8]="1111111";
   tost[9]="1111011";

   memset(dp,-1,sizeof(dp));

   fl(i,0,n) cin>>s[i];

   fl(i,0,n){
       fl(j,0,10){
//           cout<<" **** "<<tost[j]<< "  "<< s[i]<< "  "<< isValid(tost[j],s[i])<<endl;
           changes[i][j]=isValid(tost[j],s[i]);
//           cout<<changes[i][j]<<" ";
       }
   }

   int val = f(0,k,0);
   findans(0,k);

   if(val) cout<<ans<<endl;
   else cout<<-1<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
