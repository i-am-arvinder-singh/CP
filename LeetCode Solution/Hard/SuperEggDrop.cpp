int dp[101][20000];
class Solution {
    
public:
    
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    
    int superEggDrop(int k, int n) {
        
        if(dp[k][n]!=-1)
            return dp[k][n];
        
        if(n==0)
            return dp[k][n] = 0;
        
        if(k==1)
            return dp[k][n] = n;
        
        if(n==1)
            return dp[k][n] = 1;
        
        int ans = INT_MAX;
        int left = 1, right = n;
        
        while(left<=right){
            
            int mid = (left+right)/2;
            int down = 1+superEggDrop(k-1,mid-1);
            int up = 1+superEggDrop(k,n-mid);
            ans=min(ans,max(down,up));
            
            if(down<up)
                left = mid+1;
            else
                right = mid-1;
            
        }
        
        return dp[k][n] = ans;
    }
};