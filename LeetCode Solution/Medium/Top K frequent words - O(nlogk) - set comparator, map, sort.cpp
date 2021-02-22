class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> my;
        for(auto &word:words) my[word]++;
        auto cmp = [](const pair<string,int> &p1, const pair<string,int> &p2){
            if(p1.second==p2.second) {
                return p1.first>p2.first;
            } else {
                return p1.second<p2.second;
            }
        };
        set<pair<string,int>,decltype(cmp)> s(cmp);
        for(auto &[word,cnt]:my) {
            if(s.size()<k) {
                s.insert({word,cnt});
            } else {
                auto p = *s.begin();
                if(cnt>p.second) {
                    s.erase(s.begin());
                    s.insert({word,cnt});
                } else if(cnt==p.second) {
                    if(word<p.first) {
                        s.erase(s.begin());
                        s.insert({word,cnt});
                    }
                }
            }
        }
        vector<string> res;
        for(auto &[word,cnt]:s) res.push_back(word);
        reverse(res.begin(),res.end());
        return res;
    }
};