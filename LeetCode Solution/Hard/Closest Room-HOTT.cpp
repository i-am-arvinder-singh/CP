class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(),rooms.end(),[&](vector<int> &v1, vector<int> &v2){
            return v1[1] > v2[1];
        });
        for(int i=0;i<queries.size();i++) queries[i].push_back(i);
        sort(queries.begin(),queries.end(),[&](vector<int> &v1, vector<int> &v2){
            return v1[1] > v2[1];
        });
        vector<int> ans(queries.size());
        int i = 0;
        set<int> s;
        for(auto ele:queries){
            int pref_id = ele[0], minSize = ele[1], id = ele[2];
            while(i<rooms.size() && rooms[i][1]>=minSize){
                s.insert(rooms[i++][0]);
            }
            if(s.size()){
                auto it = s.upper_bound(pref_id);
                if(it==s.end()){
                    it--;
                    int res = abs(*it-pref_id);
                    ans[id] = *it;
                }
                else{
                    int res = abs(*it-pref_id);
                    ans[id] = *it;
                    if(it!=s.begin()){
                        it--;
                        if(abs(*it-pref_id)<res){
                                ans[id] = (*it);
                        }
                        else if(abs(*it-pref_id)==res){
                            if(*it < ans[id])
                                ans[id] = (*it);
                        }
                    }
                }
            }
            else{
                ans[id] = -1;
            }
        }
        return ans;
    }
};









