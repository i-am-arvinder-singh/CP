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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)         2*x+2

const double pi = acos(-1.0);

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<int> track[n+1];
    int diff[n+1];
    for(int i=1;i<=n;i++) track[i].pb(0);
    for(int i=1;i<=n;i++) track[v[i]].pb(i);
    for(int i=1;i<=n;i++) track[i].pb(n+1);
    for(int i=1;i<=n;i++){
        int mx = 0;
        for(int j=1;j<(int)track[i].size();j++){
            mx = max(mx,track[i][j]-track[i][j-1]);
        }
        diff[i] = mx;
    }
    int ans[n+1];
    for(int i=0;i<=n;i++) ans[i] = -1;
    for(int i=1;i<=n;i++){
        if(diff[i]==n+1) continue;
        for(int j=diff[i];j<=n && ans[j]==-1;j++){
            ans[j] = i;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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

