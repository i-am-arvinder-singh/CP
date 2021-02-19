class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n = nums.size();
        int ans = 0;
        int prod = 1;
        int i = 0;
        int left = 0;
        while(i<n){
            prod*=nums[i];
            while(prod>=k){
                prod/=nums[left++];
            }
            ans+=(i-left+1);
            i++;
        }
        return ans;
    }
};