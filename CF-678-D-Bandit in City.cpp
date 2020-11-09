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
#define RIGHT(x)        2*x+2

const double pi = acos(-1.0);

void solve()
{
    //The trick was to distribute a[node] among leaves
    //for better even distribution rather than in the immediate childrens of 
    //this 'node' in consideration
    int n;
    cin>>n;
    vector<vector<int>> edges(n);
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        x--;
        edges[x].pb(i);
    }
    vector<int> a(n);
    vector<pii> info(n);//ff-> ssum, ss-> no. of leaves
    for(int i=0;i<n;i++) cin>>a[i];
    std::function<int(int)> dfs = [&](int node){
        bool isChild = true;
        int ssum = 0, leafCnt = 0, ans = -inf;
        for(auto child:edges[node]){ 
            ans=max(ans,dfs(child));
            isChild = false;
            ssum += info[child].ff;
            leafCnt += info[child].ss;
        }
        info[node] = {ssum,leafCnt};
        if(isChild){
            info[node].ff += a[node];
            info[node].ss ++;
            return a[node];
        }
        int diff = ans*leafCnt-ssum;
        info[node].ff += a[node];
        if(diff >= a[node]) return ans;
        else return ans + (a[node]-diff+leafCnt-1)/leafCnt;
    };
    cout<<dfs(0);
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