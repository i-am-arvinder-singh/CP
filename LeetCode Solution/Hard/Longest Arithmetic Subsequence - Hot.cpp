class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(1002));
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int d = A[i]-A[j]+500;
                dp[i][d]=max(dp[j][d]+1,dp[i][d]);
                ans=max(ans,1+dp[i][d]);
            }
        }
        return ans;
    }
};