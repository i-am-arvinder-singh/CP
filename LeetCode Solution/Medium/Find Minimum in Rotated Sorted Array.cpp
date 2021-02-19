class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums.back();
        int i = 0, j = n-1;
        while((j-i)>1){
            int mid = i + (j-i)/2;
            if( mid-1>=0?nums[mid-1]>nums[mid]:true &&
               mid+1<n?nums[mid]<nums[mid+1]:true
            ) return nums[mid];
            else if(nums[i]<nums[mid] && nums[mid]>nums[j]) i = mid+1;
            else j=mid-1;
        }
        int ans = 1e9;
        for(int k=i;k<=j;k++) ans=min(ans,nums[k]);
        return ans;
    }
};