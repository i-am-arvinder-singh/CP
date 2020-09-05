class Solution {
    int n,m,total;
    int dp[101][101];
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<int> cnt(26,0);
        for(int i=0;i<(int)s1.length();i++) cnt[s1[i]-'a']++;
        for(int i=0;i<(int)s2.length();i++) cnt[s2[i]-'a']++;
        vector<int> match(26,0);
        for(int i=0;i<(int)s3.length();i++) match[s3[i]-'a']++;
        for(int i=0;i<26;i++){
            if(cnt[i]!=match[i]) return false;
        }
        n = s1.length();
        m = s2.length();
        total = s3.length();
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,s1,s2,s3);
    }
    bool f(int i, int j, int k, string &s1, string &s2, string &s3)
    {
        if(i+j==total) return dp[i][j] = true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s3[k] && s2[j]!=s3[k]){
            return dp[i][j] = f(i+1,j,k+1,s1,s2,s3);
        }
        else if(s1[i]!=s3[k] && s2[j]==s3[k]){
            return dp[i][j] = f(i,j+1,k+1,s1,s2,s3);
        }
        else if(s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j] = f(i+1,j,k+1,s1,s2,s3)||f(i,j+1,k+1,s1,s2,s3);
        }
        else return dp[i][j] = false;
        return false;
    }
};