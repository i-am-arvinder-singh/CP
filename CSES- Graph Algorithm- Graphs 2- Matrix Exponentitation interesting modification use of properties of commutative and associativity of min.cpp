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
#define mod             1000000007
#define inf             1e18+1000
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
#define MAX_SIZE        101

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class matExp{
public:
    matExp(int A[MAX_SIZE][MAX_SIZE], int k){
        int I[MAX_SIZE][MAX_SIZE] = {};
        for(int i=0;i<MAX_SIZE;i++) I[i][i] = 1;
        bool flag = true;
        while(k){
            if(k&1){
                if(flag){
                    for(int i=0;i<MAX_SIZE;i++)
                        for(int j=0;j<MAX_SIZE;j++)
                            I[i][j] = A[i][j];
                    flag = false;
                }
                else matMul(I,A);
            }
            matMul(A,A);
            k>>=1;
        }
        for(int i=0;i<MAX_SIZE;i++) 
            for(int j=0;j<MAX_SIZE;j++) 
                A[i][j] = I[i][j];
    }

    void matMul (int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE]){
        int temp[MAX_SIZE][MAX_SIZE];
        for(int i=0;i<MAX_SIZE;i++)
            for(int j=0;j<MAX_SIZE;j++){
                int ans = inf;
                for(int k=0;k<MAX_SIZE;k++)
                    if(A[i][k]==inf || B[k][j]==inf) ans = min(ans,(int)inf);
                    else ans=min(ans,A[i][k]+B[k][j]);
                temp[i][j] = ans;
            }
        for(int i=0;i<MAX_SIZE;i++)
            for(int j=0;j<MAX_SIZE;j++)
                A[i][j] = temp[i][j];
    }

};

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int matrix[MAX_SIZE][MAX_SIZE];
    for(int i=0;i<MAX_SIZE;i++){
        for(int j=0;j<MAX_SIZE;j++){
            matrix[i][j] = inf;
        }
    }
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        matrix[x][y] = min(matrix[x][y],w);
    }
    matExp mm(matrix,k);
    if(matrix[1][n]!=inf) cout<<matrix[1][n]<<endl;
    else cout<<-1<<endl;
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

