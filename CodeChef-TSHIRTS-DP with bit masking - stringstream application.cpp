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
#define RIGHT(x)         2*x+2

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class dpBitMask{
    int n;
    vector<vector<int>> hasTshirt;
    vector<vector<int>> dp;
public:
    dpBitMask(int n){
        this->hasTshirt = vector<vector<int>> (102,vector<int> (n,0));
        this->dp = vector<vector<int>> (102,vector<int> ((1<<n)+2,-1));
        this->n = n;
        string str;
        cin.ignore();
        for(int i=0;i<n;i++){
            getline(cin,str);
            stringstream s(str);
            int val;
            while(s>>val){
                hasTshirt[val][i]=1;
            }
        }
    }

    int giveMeTheAnswer(){
        return solve(1,0);
    }

    int solve(int shirt, int mask){
        if(dp[shirt][mask]!=-1) return dp[shirt][mask];
        if(setbits(mask) == n) return dp[shirt][mask] = 1;
        if(shirt > 100) return  dp[shirt][mask] = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(mask & (1<<i)) continue;
            if(hasTshirt[shirt][i]) ans = (ans + solve(shirt+1, mask+(1<<i)))%mod;
        }
        ans = (ans + solve(shirt+1, mask) ) %mod;
        return dp[shirt][mask] = ans;
    }
};

void solve()
{
    int n;
    cin>>n;
    dpBitMask d(n);
    cout<<d.giveMeTheAnswer()<<endl;
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

