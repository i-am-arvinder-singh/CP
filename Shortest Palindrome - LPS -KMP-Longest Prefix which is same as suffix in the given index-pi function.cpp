#define all(v) v.begin(),v.end()

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s=="") return s;
        string original_string = s;
        int val = original_string.size();
        int n = s.size();
        string w = s;
        reverse(all(w));
        vector<int> lps(n,0),lps_w(n,0);
        for(int i=1;i<n;i++){
            int j = lps[i-1];
            while(j>0 && s[j]!=s[i]){
                j=lps[j-1];
            }
            if(s[j]==s[i]) j++;
            lps[i] = j;
        }
        for(int i=0;i<n;i++){
            int j = i-1>=0?lps_w[i-1]:0;
            while(j>0 && s[j]!=w[i]){
                j=lps[j-1];
            }
            if(s[j]==w[i]) j++;
            lps_w[i] = j;
        }
        string app = original_string.substr(lps_w[n-1]);
        reverse(all(app));
        original_string = app + original_string;
        return original_string;
    }
};