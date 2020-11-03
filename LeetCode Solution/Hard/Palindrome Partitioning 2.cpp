class Solution {
    int n;
    vector<vector<string>> ans;
    vector<int> dp;
public:
    int minCut(string s) {
        n = s.length();
        dp.resize(n+1,-1);
        vector<vector<bool>> isPalinDp(n+1,vector<bool>(n+1,false));
        for(int i=0;i<n;i++){
            expand_about_center(i,i,s,isPalinDp);
            if(i+1<n) expand_about_center(i,i+1,s,isPalinDp);
        }
        return f(0,s,isPalinDp)-1;
    }
    
    void expand_about_center(int i, int j, string &s, vector<vector<bool>> &isPalinDp)
    {
        while(i>=0 && j<n && s[i]==s[j]){
            isPalinDp[i][j]=true;
            i--;
            j++;
        }
    }
    
    int f(int id, string &s,vector<vector<bool>> &isPalinDp)
    {
        if(dp[id]!=-1) return dp[id];
        if(id==n){
            return dp[id]=0;
        }
        int ans = 1e9;
        for(int i=n-1;i>=id;i--){
            // string w = s.substr(id,i-id+1); 
            if(isPalinDp[id][i]){
                int temp = 1;
                temp = 1+f(i+1,s,isPalinDp);
                ans=min(ans,temp);
                // break;
            }
        }
        return dp[id]=ans;
    }
};