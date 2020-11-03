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

class DigitDp{
    int n;
    vector<int> limits;
    int dp[11][100][2];
public:
    DigitDp(string s){
        this->n = (int)s.size();
        limits = vector<int> (n);
        for(int i=0;i<n;i++) limits[i] = s[i] - '0';
        memset(dp,-1,sizeof(dp));
    }

    int answerHelper(){
        return getSum(0,0,true);//(pos,sum,flag)
        //flag that indicates wether we have to go till limit or not 
        //flag == true -> means go till limit
        //        false-> means go beyond limit
    }

    int getSum(int pos,int sum ,bool flag){
        if(dp[pos][sum][flag]!=-1) return dp[pos][sum][flag];
        if(pos>=n) return dp[pos][sum][flag] = sum;
        int upto;
        if(flag) upto = limits[pos];
        else     upto = 9;
        int retVal = 0;
        for(int i=0;i<=upto;i++){
            if(i<upto || flag==false) retVal += getSum(pos+1,sum+i,false);
            else       retVal += getSum(pos+1,sum+i,true);
        }
        return dp[pos][sum][flag] = retVal;
    }
};

void solve()
{
    while(true){
        int a,b;
        cin>>a>>b;
        if(a==-1 && b==-1){
            return;
        }
        DigitDp dLeft(to_string(a-1)), dRight(to_string(b));
        cout<<dRight.answerHelper()-dLeft.answerHelper()<<endl;
    }
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