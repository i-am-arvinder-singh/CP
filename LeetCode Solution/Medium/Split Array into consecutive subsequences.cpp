class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> hypo;
        for(auto &num:nums) freq[num]++;
        for(auto &ele:nums) {
            if(freq[ele]==0) continue;
            else if(hypo[ele]) {
                hypo[ele]--;
                hypo[ele+1]++;
                freq[ele]--;
            } else if(freq[ele]>0 && freq[ele+1]>0 && freq[ele+2]>0) {
                freq[ele]--;
                freq[ele+1]--;
                freq[ele+2]--;
                hypo[ele+3]++;
            } else return false;
        }
        return true;
    }
};