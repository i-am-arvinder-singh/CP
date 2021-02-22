class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> v,first(n),second(n);
        for(int i=0;i<n;i++) {
            if(v.empty()) {
                v.push_back(nums[i]);
                continue;
            }
            auto it = lower_bound(v.begin(),v.end(),nums[i]);
            first[i] = it - v.begin();
            if(it==v.end()) v.push_back(nums[i]);
            else *it = nums[i];
        }
        v.clear();
        for(int i=n-1;i>=0;i--) {
            if(v.empty()) {
                v.push_back(nums[i]);
                continue;
            }
            auto it = lower_bound(v.begin(),v.end(),nums[i]);
            second[i]=it-v.begin();
            if(it==v.end()) v.push_back(nums[i]);
            else *it = nums[i];
        }
        int ans = 1000000000;
        for(int i=1;i<n-1;i++) {
            if(first[i] && second[i]) ans=min(ans,n-(first[i]+second[i]+1));
        }
        return ans;
    }
};