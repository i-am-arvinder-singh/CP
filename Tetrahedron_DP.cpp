#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1

int dp[2][2];

//Matrix exponentiation implementation makes it even faster // Not done yet


int find_ans(int N,int s,int d)
    {
        if(dp[N][s]!=-1)
            return dp[N][s];
        if(s==d && N==0)
            return 1;
        else if(s!=d && N==0)
            return 0;
        return dp[N][s]=find_ans(N-1,(s+1)%4,d)+find_ans(N-1,(s+2)%4,d)+find_ans(N-1,(s+3)%4,d);
    }

int find_ans_bottom_up(int N,int s,int d)
    {
        dp[0][0]=1,dp[0][1]=0,dp[0][2]=0,dp[0][3]=0;
        for(int i=1;i<=N;i++)
        {

            dp[i%2][0]=(dp[(i-1)%2][1]+dp[(i-1)%2][2]+dp[(i-1)%2][3])%mod;
            dp[i%2][1]=(dp[(i-1)%2][0]+dp[(i-1)%2][2]+dp[(i-1)%2][3])%mod;
            dp[i%2][2]=(dp[(i-1)%2][0]+dp[(i-1)%2][1]+dp[(i-1)%2][3])%mod;
            dp[i%2][3]=(dp[(i-1)%2][0]+dp[(i-1)%2][1]+dp[(i-1)%2][2])%mod;
        }
        return dp[N%2][0];
    }

int genius(int N)//Heavily optimized//0->different 1->same
    {
        dp[0][0]=0,dp[1][0]=1;
        for(int i=1;i<=N;i++)
        {
            dp[1][i%2]=(3*dp[0][(i-1)%2])%mod;
            dp[0][i%2]=(2*dp[0][(i-1)%2]+dp[1][(i-1)%2])%mod;
        }
        return dp[1][N%2];
    }


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
	int n;
    cin>>n;
    cout<<genius(n);
	return 0;
}
