#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
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
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void add(int &a, int b)
{
    b%=mod;
    a = (a+b)%mod;
}

void matMul(int A[5][5], int B[5][5])
{
    int temp[5][5]={};
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k =0;k<5;k++){
                add(temp[i][j],A[i][k]*B[k][j]);
            }
        }
    }
    fl(i,0,5) fl(j,0,5) A[i][j]=temp[i][j];
}

void matExp(int A[5][5], int p)
{
    int I[5][5]={};
    for(int i=0;i<5;i++) I[i][i]=1;
    while(p){
        if(p&1) matMul(I,A);
        matMul(A,A);
        p>>=1;
    }
    fl(i,0,5) fl(j,0,5) A[i][j]=I[i][j];
}

void solve()
{
    int n;
    cin>>n;
    int A[5][5] = {{1,1,1,1,1},
                     {1,0,0,1,0},
                     {1,0,0,0,0},
                     {1,1,0,0,0},
                     {1,0,0,0,0}};
    matExp(A,n);
    int ans = 0;
    for(int i=0;i<5;i++) add(ans,A[0][i]);
    cout<<ans-1<<endl;
}

int32_t main()
{
	omniphantom
	#if 1
	w(t)
	#endif // 0
    solve();
	return 0;
}
