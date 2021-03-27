class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        
        int n = values.size();
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        
        std::function<int(int,int)> f = [&](int i, int j){
            if(dp[i][j]!=-1) return dp[i][j];
            if(i+1==j) return 0;
            int ans = 1000000000;
            for(int k=i+1;k<j;k++){
                int calc = values[i]*values[j]*values[k];
                ans=min(ans,calc+f(i,k)+f(k,j));
            }
            return dp[i][j] = ans;
        };
        
        return f(0,n-1);
        
    }
};