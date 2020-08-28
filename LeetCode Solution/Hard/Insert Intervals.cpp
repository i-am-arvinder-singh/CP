class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        int n_st = *newInterval.begin(), n_en = *prev(newInterval.end());
        vector<int> temp;
        if(n_en<intervals[0][0]){
            ans.push_back(newInterval);
        }
        for(int i=0;i<(int)intervals.size();i++){
            int st = intervals[i][0], en = *prev(intervals[i].end());
            if(i>0){
                if(intervals[i-1][intervals[i-1].size()-1]<n_st && n_en<intervals[i][0]){
                    ans.push_back(newInterval);
                }
            }
            if(en<n_st || n_en<st) {
                if(!temp.empty()){
                    ans.push_back(temp);
                    temp.clear();
                }
                ans.push_back(intervals[i]);
            }
            else{
                if(temp.empty()){
                    int first = min(st,n_st);
                    int last  = max(en,n_en);
                    temp.push_back(first);
                    temp.push_back(last);
                }
                else{
                    int first = min(st,*temp.begin());
                    int last  = max(en,*prev(temp.end()));
                    temp[0]=first;
                    temp[temp.size()-1]=last;
                }
            }
        }
        if(!temp.empty()){
            ans.push_back(temp);
        }
        if(intervals[intervals.size()-1][intervals[intervals.size()-1].size()-1]<n_st){
            ans.push_back(newInterval);
        }
        return ans;
    }
};