class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums.back();
        int i = 0, j = n-1;
        while((j-i)>1){
            int mid = i + (j-i)/2;
            if(nums[mid]<nums[j]) j = mid;
            else if(nums[mid]>nums[j]) i = mid;
            else j--;
        }
        int ans = 1e9;
        for(int k=i;k<=j;k++) ans=min(ans,nums[k]);
        return ans;
    }
};