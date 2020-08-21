class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        string newp;
        n=s.size(),m=p.size();
        for(int i=0;i<m;){
            if(p[i]=='*'){
                newp=newp+'*';
                i++;
                while(p[i]=='*' &&i<m) i++;
            }
            else{
                newp=newp+p[i];
                i++;
            }
        }
        m=newp.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return f(s,newp,0,0);
    }
    
    bool f(string &s, string &p, int i, int j)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n){
            while(p[j]=='*') j++;
            return dp[i][j]=(j==m);
        }
        if(j==m) return dp[i][j]=(i==n);
        if(s[i]==p[j]){
            return dp[i][j]=f(s,p,i+1,j+1);
        }
        else if(p[j]=='*'){
            if(f(s,p,i,j+1)) return dp[i][j]=true;
            while(i<n){
                if(f(s,p,i+1,j+1)) return dp[i][j]=true;
                else i++;
            }
            return dp[i][j]=false;
        }
        else if(p[j]=='?'){
            return dp[i][j]=f(s,p,i+1,j+1);
        }
        return dp[i][j]=false;
    }
};