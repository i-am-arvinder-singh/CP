class Solution {
public:
    int longestSubstring(string s, int k) {
        std::function<int(int,int)> solve = [&](int left, int right){
            if(right-left+1<k) return 0;
            vector<int> v(26);
            for(int i=left;i<=right;i++) v[s[i]-'a']++;
            for(int i=left;i<=right;i++){
                if(v[s[i]-'a']==0) continue;
                if(v[s[i]-'a']<k){
                    return max(solve(left,i-1),solve(i+1,right));
                }
            }
            return right-left+1;
        };
        return solve(0,(int)s.length()-1);
    }
};