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

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n;
    cin>>n;
    vector<int> p,e;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            p.pb(i);
            e.pb(0);
            while(n%i==0){
                n/=i;
                e.back()++;
            }
        }
    }
    if(n>1){
        p.pb(n);
        e.pb(1);
    }
    int k = p.size();
    vector<vector<int>> d(k);
    d.back().pb(p[0]*p.back());
    std::function<void(int,int,int)> dfs = [&](int node, int val, int t){
        if(node==k){
            if(t==-1) return;
            if(val == p[0]*p.back()) return;
            d[t].pb(val);
            return;
        }
        dfs(node+1,val,t);
        for(int i=1;i<=e[node];i++){
            val*=p[node];
            dfs(node+1,val,(t==-1)?node:t);
        }
    };
    dfs(0,1,-1);
    int ans = k==2 && e[0]==1 && e[1]==1;
    for(int i=0;i<k;i++){
        for(auto &x:d[i]){
            if(x%p[(i+1)%k]==0){
                swap(x,d[i].back());
                break;
            }
        }
        for(auto x:d[i]) cout<<x<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
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

