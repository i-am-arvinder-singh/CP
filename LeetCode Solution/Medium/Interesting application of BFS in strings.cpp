class Solution {
vector<vector<pair<int,int>>> g;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(auto x:wordList) s.insert(x);
        if(s.count(endWord)==0) return 0;
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty()){
            int w = q.size();
            while(w--){
                string cur = q.front();
                q.pop();
                int len = cur.length();
                for(int i=0;i<len;i++){
                    string temp = cur;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        if(temp==endWord){
                            return level+1;
                        }
                        if(s.find(temp)!=s.end()){
                            s.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};