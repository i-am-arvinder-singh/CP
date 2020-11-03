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

void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[n],c[n];
    fl(i,0,n) cin>>a[i];
    fl(i,0,n) cin>>b[i];
    sort(b,b+n);
    int ans = inf;
    fl(i,0,n){
        int diff;
        if(a[0]<b[i]){
            diff=b[i]-a[0];
        }
        else{
            diff = m-a[0]+b[i];
        }
        diff%=m;
        fl(i,0,n){
            c[i]=(a[i]+diff)%m;
        }
        sort(c,c+n);
        bool flag = true;
        fl(i,0,n){
            if(b[i]!=c[i]){
                flag=false;
                break;
            }
        }
        if(flag) ans=min(ans,diff);
    }
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
