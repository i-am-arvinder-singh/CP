#include<bits/stdc++.h>
using namespace std;
 
template<typename T1, typename T2> T1 amax(T1 &a, T2 b) {if(b>a){a=b;} return a;};
 
const int MAX1 = 2;
const int MAX2 = 2e6+5;
 
int main()
{
    int n,c ;
    cin>> n >> c;
    int w[n+1], v[n+1];
 
    for(int i=0; i<n ;i++) cin>>v[i+1];
    for(int i=0; i<n ;i++) cin>>w[i+1];
    
    int dp[2][2000005];
    memset(dp,-1,sizeof(dp));
 
    for(int i=0 ; i<=c ; i++) {
        dp[0][i]=0;
    }
    for(int i=0 ; i<MAX1 ; i++) {
        dp[i][0]=0;
    }
    int mx = 0;
    int x=1,y=0;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=c; j++){
            amax(dp[x][j],dp[y][j]);
            if(j-w[i]>=0) amax(dp[x][j],v[i]+dp[y][j-w[i]]);
        }
        x^=1,y^=1;
    }
    cout<<dp[n%2][c]<<endl;
}