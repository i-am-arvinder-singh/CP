#define ff first
#define ss second

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int,int>> points;
        multiset<int> s;
        s.insert(0);
        int pre = 0;
        for(int i=0;i<buildings.size();i++){
            points.push_back({buildings[i][0],-buildings[i][2]});
            points.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(points.begin(),points.end(),[&](auto &p1, auto &p2){
            if(p1.ff==p2.ff) return p1.ss<p2.ss;
            return p1.ff<p2.ff;
        });
        for(auto p:points){
            if(p.ss<0){
                s.insert(-p.ss);
            }
            else{
                s.erase(s.find(p.ss));
            }
            int cur = *prev(s.end());
            if(pre!=cur){
                vector<int> temp;
                temp.push_back(p.ff);
                temp.push_back(cur);
                res.push_back(temp);
                pre = cur;
            }
        }
        return res;
    }
};


