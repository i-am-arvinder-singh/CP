class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        if(right==0) return 0;
        while(left<right){
            int mid = left + ((right-left)>>1);//Prevents untowards oveflow
            if(nums[mid]<nums[mid+1]){
                left=mid+1;
            }
            else right = mid;
        }
        return left;
    }
};