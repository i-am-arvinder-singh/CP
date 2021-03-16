class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[&](const vector<int> &v1, const vector<int> &v2){
            if(v1[0]<v2[0]) return true;
            else if(v1[0]==v2[0]){
                return v1[1]>v2[1];
            }
            else{
                return false;
            }
        });
        vector<int> t;
        for(int i=0;i<n;i++) t.push_back(envelopes[i][1]);
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(temp.empty()) temp.push_back(t[i]);
            else{
                if(t[i]>temp.back()) temp.push_back(t[i]);
                else{
                    int id = lower_bound(temp.begin(),temp.end(),t[i]) - temp.begin();
                    temp[id] = t[i];
                }
            }
        }
        return temp.size();
    }
};