class Solution {
vector<vector<int>> g;
vector<int> score;
int longest(int v)
{
    if(score[v]>0) return score[v];
    score[v]=1;
    for(auto next:g[v]){
        score[v]=max(score[v],longest(next)+1);
    }
    return score[v];
}
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        g.clear();
        g.resize(n);
        score.clear();
        score.resize(n);
        unordered_map<string,int> my;
        for(int i=0;i<n;i++){
            my[words[i]]=i;
        }
        for(int i=0;i<n;i++){
            for(int len=0;len<(int) words[i].length();len++){
                string check = words[i].substr(0,len) + words[i].substr(len+1);
                auto it = my.find(check);
                if(it==my.end()) continue;
                g[it->second].push_back(i);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans=max(ans,longest(i));
        }
        return ans;
    }
};