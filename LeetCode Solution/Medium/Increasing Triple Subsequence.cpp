class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int v1 = INT_MAX, v2 = INT_MAX;
        for(auto ele:nums){
            if(ele<=v1) v1=ele;
            else if(ele<=v2) v2=ele;
            else return true;
        }
        return false;
    }
};