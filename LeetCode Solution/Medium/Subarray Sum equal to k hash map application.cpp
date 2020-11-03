class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pref=0, ans = 0;
        unordered_map<int,int> my;
        my[pref]++;
        for(int R=0;R<n;R++){
            pref+=nums[R];
            int val = pref-k;//pref[R]-pref[L-1]==k
            ans += my[val];
            my[pref]++;
        }
        return ans;
    }
};