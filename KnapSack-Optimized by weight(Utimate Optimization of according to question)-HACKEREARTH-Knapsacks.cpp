#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c;
    cin>>n>>c;
    int v[n+1], w[n+1];
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>w[i];
    int size = 50*n;
    vector<int> dp(size+2,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=size;j>=0;j--){
            int temp = INT_MAX;
            if(j-v[i]>=0){
                if(dp[j-v[i]]<temp) temp=w[i]+ dp[j-v[i]];
                dp[j]=min(dp[j],temp);
            }
        }
    }
    for(int j=size;j>=0;j--){
        if(dp[j]<=c){
            cout<<j<<endl;
            return 0;
        }
    }
}
