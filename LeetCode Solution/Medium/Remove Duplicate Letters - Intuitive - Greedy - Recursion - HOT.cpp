class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.empty()) return "";
        vector<int> v(26);
        for(auto ele:s) v[ele-'a']++;
        int pos = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]<s[pos]) pos = i;
            v[s[i]-'a']--;
            if(v[s[i]-'a']==0) break;
        }
        string next = s.substr(pos+1);
        string next_;
        for(auto ele:next) if(ele!=s[pos]) next_+=ele;
        return s[pos]+removeDuplicateLetters(next_);
    }
};