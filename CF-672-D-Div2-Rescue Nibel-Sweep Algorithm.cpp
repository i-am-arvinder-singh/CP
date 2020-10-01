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
#define BIT             1

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<pii> v;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        v.pb({l,0});
        v.pb({r,1});
    }
    sort(v.begin(),v.end());
    const int MAX = 3e5+3;
    vector<int> fact(MAX);
    fact[0]=fact[1]=1;
    for(int i=1;i<MAX;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
    auto power = [&](int base, int exp){
        int ans = 1;
        while(exp){
            if(exp&1){
                ans*=base;
                ans%=mod;
            }
            base*=base;
            base%=mod;
            exp>>=1;
        }
        return ans%mod;
    };
    auto inverse = [&](int val){
        return power(val,mod-2);
    };
    auto mul = [&](int x, int y){
        x%=mod;
        y%=mod;
        return (x*y)%mod;
    };
    auto ncr = [&](int n, int r){
        return mul(fact[n], mul(inverse(fact[r]),inverse(fact[n-r])) );
    };
    auto add = [&](int &x, int y){
        x%=mod;
        y%=mod;
        x = (x+y)%mod;
        return x;
    };
    int on = 0, ans = 0;
    for(int i=0;i<(int)v.size();i++){
        auto p = v[i];
        if(p.ss==0){
            if(on>=k-1){
                add(ans,ncr(on,k-1));
            }
            on++;
        }
        else on--;
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

