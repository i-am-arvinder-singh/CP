class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return false;
        int left = 0, right = n-1;
        int mid;
        while(left<right){
            mid = left+(right-left)/2;
            if(nums[mid]==target || nums[left]==target || nums[right]==target) return true;
            if(nums[mid]>nums[right]) left=mid+1;
            else if(nums[mid]<nums[right]) right=mid;
            else{
                right--;
            }
        }
        if(right==0){
            left = 0, right = n-1;
            while(left<=right){
                mid = left+(right-left)/2;
                if(nums[mid]==target || nums[left]==target || nums[right]==target) return true;
                else if(nums[mid]<target) left=mid+1;
                else right=mid-1;
            }
            return false;
        }
        else if(right==n-1){
            if(target==nums[right]) return true;
            left = 0 ,right = n-2;
            while(left<=right){
                mid = left+(right-left)/2;
                if(nums[mid]==target || nums[left]==target || nums[right]==target) return true;
                else if(nums[mid]<target) left=mid+1;
                else right=mid-1;
            }
            return false;
        }
        else{
            int left1 = 0, right1 = right-1, left2 = right, right2 = n-1;
            while(left1<=right1){
                mid = left1+(right1-left1)/2;
                if(nums[mid]==target || nums[left1]==target || nums[right1]==target) return true;
                else if(nums[mid]<target) left1=mid+1;
                else right1=mid-1;
            }
            while(left2<=right2){
                mid = left2+(right2-left2)/2;
                if(nums[mid]==target || nums[left2]==target || nums[right2]==target) return true;
                else if(nums[mid]<target) left2=mid+1;
                else right2=mid-1;
            }
            return false;
        }
    }
};




