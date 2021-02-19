class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xor_ = 0;
        for(auto num:nums) xor_^=num;
        xor_&=-xor_;
        vector<int> res(2);
        for(auto num:nums){
            if(num&xor_) res[0]^=num;
            else res[1]^=num;
        }
        return res;
    }
};