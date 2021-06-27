class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[&](const vector<int> &v1, const vector<int> &v2){
            if(v1[0]==v2[0]) return v1[1]<v2[1];
            return v1[0]<v2[0];
        });
        int i = 0, ans = 0;
        int n = events.size();
        multiset<int> m;
        for(int day=1;day<=100000;day++){
            while(!m.empty() && (*m.begin())<day ){
                m.erase(m.begin());
            }
            while(i<n && events[i][0]<=day){
                m.insert(events[i++][1]);
            }
            if(!m.empty()){
                m.erase(m.begin());
                ans++;
            }
        }
        return ans;
    }
};






