class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while((i-1)>=0 && nums[i-1]>=nums[i]) i--;
        if(i==0) reverse(nums.begin(),nums.end());
        else{
            int left = i, right = n-1;
            int &val = nums[i-1];
            reverse(nums.begin()+left,nums.begin()+right+1);
            auto id = upper_bound(nums.begin()+left,nums.begin()+right+1,val)-nums.begin();
            swap(nums[id],val);
        }
    }
};