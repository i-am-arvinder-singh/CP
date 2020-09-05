class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int len = t.length();
        string str = "";
        if(n==0 || len==0) return str;
        unordered_map<char,int> my;
        for(auto ch:t) my[ch]++;
        int cnt = 0, j =0;
        int ans = 1e9;
        for(int i=0;i<n;i++){
            if(--my[s[i]]>=0) cnt++;
            while(len==cnt){
                if(i-j+1<ans){
                    ans=i-j+1;
                    str=s.substr(j,i-j+1);
                }
                if(++my[s[j++]]>0) cnt--;
            }
        }
        return str;
    }
};






