class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n);
        int mx = INT_MIN;
        dp[0]=nums[0];
        mx=max(mx,nums[0]);
        for(int i=1;i<n;i++){
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};