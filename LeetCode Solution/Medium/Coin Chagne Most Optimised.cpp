class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int i = 0;
        int inf = 1e9;
        vector<int> dp(amount+2,inf);
        dp[0] = 0;
        for(int i=0;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i>=coins[j]){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        return dp[amount]==inf?-1:dp[amount];
    }
};