class TrieNode{
    public:
        bool isPresent = false;
        map<char,TrieNode*> v;
};

class WordDictionary {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string v) {
        int n = v.size();
        int i = 0;
        TrieNode* temp = root;
        while(i<n-1){
            char ch = v[i];
            if(temp->v.find(ch)!=temp->v.end()){
                temp = temp->v[ch];
            }
            else{
                temp->v[ch] = new TrieNode();
                temp = temp->v[ch];
            }
            i++;
        }
        char ch = v[n-1];
        if(temp->v.find(ch)!=temp->v.end()){
            temp = temp->v[ch];
            temp->isPresent = true;
        }
        else{
            temp->v[ch] = new TrieNode();
            temp = temp->v[ch];
            temp->isPresent = true;
        }
    }
    
    bool search(string v) {
        int n = v.size();
        int i = 0;
        TrieNode* w = root;
        
        std::function<bool(TrieNode*,int)> f = [&](TrieNode* temp,int i){
            if(i>=n) return true;
            while(i<n-1){
                char ch = v[i];
                if(ch=='.'){
                    bool check = false;
                    for(auto [x,y]:temp->v){
                        check=check||f(y,i+1);
                    }
                    return check;
                }
                if(temp->v.find(ch)!=temp->v.end()){
                    temp = temp->v[ch];
                }
                else return false;
                i++;
            }
            char ch = v[n-1];
            if(ch=='.'){
                bool check = false;
                for(auto [x,y]:temp->v){
                    if(y->isPresent) return true;
                }
                return check;
            }
            if(temp->v.find(ch)!=temp->v.end()){
                temp = temp->v[ch];
                if(temp->isPresent) return true;
            }
            else return false;
            return false;
        };
        return f(w,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */