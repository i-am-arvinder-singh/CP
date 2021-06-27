class Solution {
public:
    int videoStitching(vector<vector<int>>& v, int T) {
        sort(v.begin(),v.end(),[&](const vector<int> &v1, const vector<int> &v2){
            return v1[0] < v2[0];
        });
        int st = 0, end = 0;
        int i = 0;
        int ans = 0;
        while(st<T){
            while(i<v.size() && v[i][0]<=st){
                end=max(end,v[i++][1]);
            }
            if(st==end) return -1;//No new start found
            st = end;
            ans++;
        }
        return ans;
    }
};





