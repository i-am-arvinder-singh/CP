class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int ans = 0, val=1;
        int n = nums.size();
        for(int i=0;i<32;i++){
            int cnt = 0;
            for(int i=0;i<n;i++){
                // if(nums[i]&val)
                    cnt+=((nums[i]&val)==val);//Apradh 
            }
            if(cnt%3) ans+=val;
            val<<=1;
        }
        return ans;
    }
};