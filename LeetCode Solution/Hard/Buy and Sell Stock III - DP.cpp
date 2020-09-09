class Solution {
    int n;
    int dp[3][2][100003];
public:
    int maxProfit(vector<int>& p) {
        n = p.size();
        //f(transactions,bought or not, ith id, buy_id)
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,p);
    }
    int f(int t, int b, int id, vector<int> &p)
    {
        if(dp[t][b][id]!=-1) return dp[t][b][id];
        //Buy
        if(t==2 || id>=n) return dp[t][b][id]=0;
        int a1=0,b1=0,c1=0;
        if(b!=1){
            a1=f(t,1,id+1,p)-p[id];
        }
        //Sell
        if(b==1){
            b1=p[id]+f(t+1,0,id+1,p);
        }
        //Skip
        c1=f(t,b,id+1,p);
        return dp[t][b][id]=max({a1,b1,c1});
    }
};