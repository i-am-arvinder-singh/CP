#define pb push_back
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int left = 0, right = 0;
        for(auto &ele:nums) right+=ele;
        int ans = right;
        std::function<bool(int)> isValid = [&](int mid){
            int cur_sum = 0;
            int no_of_partitions = 1;
            for(int i=0;i<n;i++){
                if(nums[i]>mid) return false;
                else if(cur_sum+nums[i]<=mid){
                    cur_sum+=nums[i];
                }
                else{
                    cur_sum = nums[i];
                    no_of_partitions++;
                    if(no_of_partitions>m) return false;
                }
            }
            return true;
        };
        while(left<=right){
            int mid = left + (right-left)/2;
            if(isValid(mid)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};