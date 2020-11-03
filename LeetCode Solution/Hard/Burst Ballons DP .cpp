class Solution {
public:
    int maxCoins(vector<int>& A) {
        int n = A.size();
        if(n==0) return 0;
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int len = 1; len<=n; len++){//For all window sizes
            for(int L=0;L<n-len+1;L++){
                int R = L+len-1;
                for(int i=L;i<=R;i++){
                    dp[L][R]=max(dp[L][R],
                                 A[i]*(L!=0?A[L-1]:1)*(R!=n-1?A[R+1]:1)
                                 +(i!=0?dp[L][i-1]:0)
                                 +(i!=(n-1)?dp[i+1][R]:0)
                                );
                }
            }
        }
        return dp[0][n-1];
    }
};