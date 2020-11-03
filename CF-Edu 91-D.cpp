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

int solve()
{
    int n,m,k,x,y;
    cin>>n>>m>>x>>k>>y;
    int a[n+4]={},b[m+4]={};
    fl(i,0,n) cin>>a[i];
    fl(i,1,m+1) cin>>b[i];
    int ans = 0, j=0;
    fl(i,1,m+2){
        int st = j, mx=-1;
        while(j<=n && a[j]!=b[i]) mx=max(mx,a[j++]);
        if(j>n) return cout<<-1,0;
        int len = j-st;
        if(mx>b[i]&&mx>b[i-1]){
            if(len<k) return cout<<-1,0;
            ans+=x;
            len-=k;
        }
        if(y*k<=x) ans+=(y*len);
        else ans+=(x*(len/k)+y*(len%k));
        j++;
    }
    cout<<ans;
    return 0;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
