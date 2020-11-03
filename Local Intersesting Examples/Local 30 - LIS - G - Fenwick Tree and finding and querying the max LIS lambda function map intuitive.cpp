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
#define BIT             1

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> my, val;
    int cnt = 1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        my[v[i]] = 0;
    }
    for(auto p:my){
        my[p.ff] = cnt++;
    }
    cnt--;
    ///////////////Implementation of BIT////////////////
    #if BIT
    const int MAX = 1e6+5;
    vector<int> bit(MAX,0);
    auto update = [&](int idx, int val, int n){
        while(idx<=n){
            bit[idx] = max(bit[idx],val);
            idx += (idx & -idx);
        }
    };
    auto query = [&](int idx){
        int sum = 0;
        while(idx>0){
            sum=max(sum,bit[idx]);
            idx -= (idx & -idx);
        }
        return sum;
    };
    #endif
    ///////////////End of Implementation of BIT////////////////
    for(int i=0;i<n;i++){
        int temp = query(my[v[i]]-1) + v[i];//Querying the max
        update(my[v[i]], temp, cnt);
        val[v[i]] = max(val[v[i]], temp);
    }
    cout << query(cnt) << " ";
    int ans = 0;
    //////////
    auto mul = [&](int x, int y){
        x%=mod;
        y%=mod;
        return (x*y)%mod;
    };
    auto add = [&](int &x, int y){
        x%=mod;
        y%=mod;
        return x=(x+y)%mod;
    };
    //////////
    for(auto [x,y] : val){
        add(ans,mul(x,y));
    }
    cout<<ans<<endl;
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

