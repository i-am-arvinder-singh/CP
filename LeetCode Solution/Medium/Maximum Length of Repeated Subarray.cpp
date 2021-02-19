class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int16_t>> dp(2,vector<int16_t> (m+2,0));
        int16_t ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1]){
                    dp[i&1][j]=1+dp[(i-1)&1][j-1];
                }
                else dp[i&1][j]=0;
                ans=max(ans,dp[i&1][j]);
            }
        }
        return ans;
    }
};