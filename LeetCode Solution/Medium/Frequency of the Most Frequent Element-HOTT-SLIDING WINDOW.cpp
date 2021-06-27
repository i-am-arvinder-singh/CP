class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i = 1,j = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long cost = 0;
        int ans = 1;
        while(i<n){
            cost+=((long long)(i-j)*(long long)(nums[i]-nums[i-1]));
            if(cost>k){
                cost-=(nums[i]-nums[j++]);
            }
            ans=max(ans,i-j+1);
            i++;
        }
        // ans=max(ans,i-j+1);
        return ans;
    }
};