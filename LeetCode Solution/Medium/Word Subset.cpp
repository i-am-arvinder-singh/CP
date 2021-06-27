class Solution {
    bool check(string &s1, vector<int> &v){
        vector<int> my = count(s1);
        for(int i=0;i<26;i++) if(my[i]<v[i]) return false;
        return true;
    }
    
    vector<int> count(string &s){
        vector<int> temp(26);
        for(auto ele:s) temp[ele-'a']++;
        return temp;
    }
    
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        
        vector<int> max_cnt(26);
        for(int i=0;i<B.size();i++){
            vector<int> temp = count(B[i]);
            for(int i=0;i<26;i++){
                max_cnt[i]=max(max_cnt[i],temp[i]);
            }
        }
        
        for(int i=0;i<A.size();i++){
            if(check(A[i],max_cnt)) ans.push_back(A[i]);
        }
        return ans;
    }
};