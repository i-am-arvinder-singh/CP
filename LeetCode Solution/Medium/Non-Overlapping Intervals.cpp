class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int left = 0, right = 1;
        int ans = 0;
        while(right<(int)intervals.size()){
            if(intervals[left][1]<=intervals[right][0]){
                left=right;
                right++;
            }
            else if(intervals[left][1]<=intervals[right][1]){
                ans++;
                right++;
            }
            else if(intervals[left][1]>intervals[right][1]){
                ans++;
                left=right;
                right++;
            }
        }
        return ans;
    }
};