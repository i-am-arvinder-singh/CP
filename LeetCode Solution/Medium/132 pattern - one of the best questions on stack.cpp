class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int x = -1e9;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<x) return true;
            while(!st.empty() && nums[i]>st.top()){
                x=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};