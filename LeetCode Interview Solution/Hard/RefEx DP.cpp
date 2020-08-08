class Solution {
public:
    int n,m;
    bool isMatch(string s, string p) {
        s='#'+s;
        p='#'+p;
        n = s.length();
        m = p.length();
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        
        //Initial value initialization
        dp[0][0] = true;
        for(int i=1;i<=n;i++) dp[i][0]=false;
        for(int i=1;i<=m;i++) if(p[i]=='*') dp[0][i]=dp[0][i-2];
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i]==p[j] || p[j]=='.') dp[i][j]=dp[i-1][j-1];
                else if(p[j]=='*'){
                    dp[i][j]=dp[i][j-2];
                    if(p[j-1]=='.'||p[j-1]==s[i]) dp[i][j]=dp[i][j]||dp[i-1][j];
                }
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};