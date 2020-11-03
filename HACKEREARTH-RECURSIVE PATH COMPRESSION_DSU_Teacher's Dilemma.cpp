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

//Check below on how to do union operation i.e., in the main function
ini mx = 2e5;
int p[mx];

int f(int a)
{
    if(p[a]<0) return a;
    return p[a] = f(p[a]);//Like dp // path compression
}

void u(int a, int b)
{
    p[a]+=p[b];
    p[b]=a;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    fl(i,1,n+1){
        p[i]=-i;
    }
    fl(i,0,m){
        int a,b;
        cin>>a>>b;
        a=f(a),b=f(b);
        if(a!=b) u(a,b);
    }
    //Unlike the previous unaccepted solution here we have optimized
    //our solution by reduction in depth of nodes
    int ans=1;
    fl(i,1,n+1){
        if(p[i]<0){
            ans*=abs(p[i]);
            ans%=mod;
        }
    }
    cout<<ans;
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
