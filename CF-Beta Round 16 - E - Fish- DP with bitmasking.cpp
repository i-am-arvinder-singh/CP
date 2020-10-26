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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class dpBitMask{
    int n;
    vector<vector<double>> prob;
    vector<double> dp;
public:
    dpBitMask(vector<vector<double>> prob, int n){
        this->prob = prob;
        this->n = n;
        dp = vector<double> ((1ll<<n),-1.0);
    }

    void findAns(){
        for(int i=0;i<n;i++){
            int fishNo = (1ll<<i);//fishNo indicates which one of the fish is surviving
            cout<<ps(solve(fishNo),9)<<" ";
        }
    }

    double solve(int bitMask){
        //Add a new fish and find its probability of surviving it till this point
        if(dp[bitMask]!=-1) return dp[bitMask];
        if(setbits(bitMask)==n) return dp[bitMask] = 1;
        double ans = 0;
        for(int i=0;i<n;i++){
            int val = (1ll<<i);
            if(val & bitMask) continue;
            double thisPointProb = solve(bitMask^val);
            //Jisko abhi abhi add kiya usko kill karo
            double killProb = findKillProb(bitMask^val,i);//kill i
            ans+=(thisPointProb*killProb);
        }
        return dp[bitMask] = ans;
    }

    double findKillProb(int bitVal, int j){//j gets killed
        int k = setbits(bitVal);
        int denom = (k*(k-1))/2;
        double ans = 0;
        for(int i=0;i<n;i++){
            if(i==j) continue;
            if((1ll<<i)&bitVal){
                ans+=(prob[i][j]);
            }
        }
        return ans/denom;
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<vector<double>> a(n,vector<double>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    dpBitMask d(a,n);
    d.findAns();
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

