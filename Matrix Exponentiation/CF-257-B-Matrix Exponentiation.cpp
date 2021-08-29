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
#define ppii            pair<int,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void matMul(int a[2][2], int b[2][2])
{
    int c[2][2]={};
    fl(i,0,2) fl(j,0,2) fl(k,0,2) c[i][j]+=(a[i][k]*b[k][j]+mod)%mod;
    fl(i,0,2) fl(j,0,2) a[i][j]=c[i][j];
}

void matExp(int mat[2][2], int n)
{
    int I[2][2]={};
    fl(i,0,2) I[i][i]=1;
    while(n){
        if(n&1) matMul(I,mat);
        matMul(mat,mat);
        n>>=1;
    }
    fl(i,0,2) fl(j,0,2) mat[i][j]=I[i][j];
}

void solve()
{
    //THE MATRIX EXPONENTIATION
    //+ FAST EXPONENTIATION
    //geeksforgeeks.org/matrix-exponentiation/
    int x,y,n;
    cin>>x>>y>>n;
    if(n==1){ cout<<(x+mod)%mod;return;}
    if(n==2){ cout<<(y+mod)%mod;return;}
    //Our equation f_i     = f_(i-1) - f_(i-2)
    //             f_(i-1) = f_(i-1)  
    //Create a matrix
    int v[2][2] = {
        {1,-1},
        {1,0}
    };
    matExp(v,n-2);
    int ans = ((y*v[0][0]+mod)%mod+(x*v[0][1]+mod)%mod + mod)%mod;
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
