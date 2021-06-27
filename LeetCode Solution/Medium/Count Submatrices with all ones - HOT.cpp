class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i=0; i<n; i++){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==0) {
                    dp[i][j]=0;
                    continue;
                }
                // cout<<"* "<<" "<<i<<" "<<j<<" "<< (j+1<m?dp[i][j+1]:0) <<" "<<mat[i][j]<<endl;
                dp[i][j]= (j+1<m?dp[i][j+1]:0) + mat[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt = dp[i][j];
                int t = cnt;
                for(int k=i+1;k<n;k++){
                    int val = min(t,dp[k][j]);
                    t=min(t,dp[k][j]);
                    cnt+=val;
                }
                ans+=cnt;
            }
        }
        return ans;
    }
};