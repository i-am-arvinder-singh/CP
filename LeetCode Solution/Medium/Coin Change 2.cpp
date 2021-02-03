class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(n==0 && amount==0) return 1;
        else if(n==0 && amount) return 0;
        vector<vector<int>> dp(2);
        for(int i=0;i<2;i++) dp[i] = vector<int> (amount+2,0);
        for(int i=0;i<2;i++) dp[i][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i]>=0) dp[i&1][j]=(i-1>=0?dp[(i-1)&1][j]:0)+dp[i&1][j-coins[i]];
                else dp[i&1][j]=i-1>=0?dp[(i-1)&1][j]:dp[i&1][j];
            }
        }
        return dp[(n-1)&1][amount];
    }
};