struct Node{
    char val;
    Node* child[26];
    bool end;
    
    Node(char ch, bool en) {
        val=ch;
        end=en;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size()==0) return ans;
        Node *root = new Node(' ',false);
        for(auto s:strs){
            if(s=="") return ans;
            insert(root,s);
        }
        bool master = false;
        while(root){
            Node *temp = NULL;
            bool check = false;
            for(int i=0;i<26;i++){
                if(!check && (root->child)[i]){
                    temp = (root->child)[i];
                    check = true;
                }
                else if(check && (root->child)[i]){
                    master = true;
                }
            }
            if(master || check==false) break;
            ans+=(temp->val);
            if(temp->end) master = true;
            root = temp;
        }
        return ans;
    }
    void insert(Node *root, string &s)
    {
        int n = s.length();
        for(int i=0;i<n;i++){
            int ch = s[i]-'a';
            if(i==n-1){
                if((root->child)[ch]==NULL){
                    (root->child)[ch]=new Node(s[i],true);
                    (root->child)[ch]->end = true;
                }
                else{
                    (root->child)[ch]->end = true;
                }
                continue;
            }
            if((root->child)[ch]==NULL){
                (root->child)[ch]=new Node(s[i],false);
                root = (root->child)[ch];
            }
            else{
                root = (root->child)[ch];
            }
        }
    }
};