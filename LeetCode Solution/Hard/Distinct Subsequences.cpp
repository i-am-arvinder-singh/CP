class Solution {
    int n,m;
    int dp[10002][102];
public:
    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();
        memset(dp,-1,sizeof(dp));
        return f(0,0,s,t);
    }
    int f(int cur, int j, string &s ,string &t)
    {
        if(dp[cur][j]!=-1) return dp[cur][j];
        if(j==m){
            return dp[cur][j]=1;
        }
        int ans = 0;
        for(int i=cur; i<n; i++){
            if(s[i]==t[j]) ans+=f(i+1,j+1,s,t);
        }
        return dp[cur][j] = ans;
    }
};