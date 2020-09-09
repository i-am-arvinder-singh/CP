class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        using path_t = vector<int>;
        int N = wordList.size();
        vector<int> len_vec(N+1);
        
        vector<string> words = wordList;
        words.push_back(beginWord);
        
        int target = -1;
        
        vector<vector<int>> g(N+1);
        for(int i=0;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                if(isValid(words[i],words[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
            len_vec[i]=INT_MAX;
            if(words[i]==endWord) target = i;
        }
        
        if(target<0) return {};
        
        queue<int> qbfs;
        qbfs.push(N);
        len_vec[N] = 1;
        while(!qbfs.empty()){
            int val = qbfs.front();
            qbfs.pop();
            int len = len_vec[val]+1;
            for(auto ch:g[val]){
                if(len<len_vec[ch]){
                    len_vec[ch] = len;
                    qbfs.push(ch);
                }
            }
        }
        
        if(len_vec[target]==INT_MAX) return {};
        
        vector<path_t> q,paths;//Vector acts as stack in dfs
        q.push_back(path_t{N});
        
        //dfs call
        while(!q.empty()){
            auto path = q.back();
            q.pop_back();
            int val = path.back();
            for(auto ch:g[val]){
                if(len_vec[ch]!=len_vec[val]+1) continue;
                path_t p(path);
                p.push_back(ch);
                if(ch==target) paths.push_back(p);
                else           q.push_back(p);
            }
        }
        
        for(auto path:paths){
            vector<string> ss;
            for(auto val:path) ss.push_back(words[val]);
            res.push_back(ss);
        }
        
        return res;
        
    }
    
    bool isValid(string &s1, string &s2){
        int cnt = 0;
        for(int i=0;i<(int)s1.size();i++){
            if(s1[i]!=s2[i]) cnt++;
        }
        return cnt==1;
    }
};