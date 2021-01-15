class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int i = 0;
        int inf = 1e9;
        vector<vector<int>> dp(n+2);
        for(int i=0;i<n+2;i++) dp[i] = vector<int> (amount+10,inf);
        for(int i=0;i<n+2;i++) dp[i][0] = 0;
        for(int i=0;i<n;i++){
            for(int amt = 1; amt<=amount;amt++){
                if(amt-coins[i]>=0)
                    dp[i][amt]=min({i-1>=0?dp[i-1][amt]:inf,1+dp[i][amt-coins[i]],i-1>=0?1+dp[i-1][amt-coins[i]]:inf});
                else{
                    dp[i][amt]=min({dp[i][amt],i-1>=0?dp[i-1][amt]:inf});
                }
            }
        }
        return dp[n-1][amount]==inf?-1:dp[n-1][amount];
    }
};