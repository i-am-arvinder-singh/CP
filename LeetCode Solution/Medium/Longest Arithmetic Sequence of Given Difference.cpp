class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int> my;
        int ans = 0;
        for(int i=0;i<n;i++){
            my[arr[i]]=max(my[arr[i]],1+my[arr[i]-difference]);
            ans=max(ans,my[arr[i]]);
        }
        return ans;
    }
};