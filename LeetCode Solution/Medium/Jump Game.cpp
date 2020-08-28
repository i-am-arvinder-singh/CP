class Solution {
    int n;
public:
    bool canJump(vector<int>& nums) {
        n = nums.size();
        if(n==0 || n==1) return true;
        int mx = -1;
        for(int i=0;i<n-1;i++){
            mx=max(mx,i+nums[i]);
            if(mx==i) return false;
        }
        return true;
    }
};