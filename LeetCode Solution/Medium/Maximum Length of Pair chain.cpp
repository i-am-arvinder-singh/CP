class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),[&](auto prev, auto cur){
            return prev[0]<cur[0];
        });
        int last = INT_MIN;
        int ans = 0;
        int n = v.size();
        for(int i=0;i<n;i++){
            if(last<v[i][0]){
                last = v[i][1];
                ans++;
            }
            else{
                last=min(last,v[i][1]);
            }
        }
        return ans;
    }
};