#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

//#define endl            "\n"
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

int f(int x, int a[], int n)
{
    int cur = 0;
    int ans = 0;
    fl(i,0,n){
        int t = x*a[i];
        cur+=t;
        ans=max(ans,cur);//Kadane's Algorithm kind of 
        if(cur<0) cur=0;
    }
    //finding maximum sum subsequence in the array
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int a[n],sum=0;
    fl(i,0,n){
        if(s[i]==t[i]) a[i]=0;
        else if(s[i]=='1') a[i]=1;
        else a[i]=-1;
        sum+=a[i];
    }
    if(sum!=0){
        cout<<-1<<endl;
        return;
    }
    int ans = max(f(1,a,n),f(-1,a,n));
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
