class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> s;
        for(auto x:nums) s.insert(x);
        int ans = 1;
        while(!s.empty()){
            int val = *s.begin();
            s.erase(val);
            int lb = val-1, ub = val+1;
            while(s.count(lb)){
                s.erase(lb);
                lb--;
            }
            while(s.count(ub)){
                s.erase(ub);
                ub++;
            }
            ub--,lb++;
            ans=max(ans,ub-lb+1);
        }
        return ans;
    }
};