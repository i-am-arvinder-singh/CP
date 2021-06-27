class Solution {
public:
    int findIntegers(int num) {
        
        int num_ = num;
        int tot_bits = 0;
        while(num_){
            num_/=2;
            tot_bits++;
        }
        
        int dp[35][2][35];
        memset(dp,-1,sizeof(dp));
        
        
        std::function<int(int,int,int)> f = [&](int i, int t, int b){
            if(dp[i][t][b]!=-1) return dp[i][t][b];
            if(i==b-1) return dp[i][t][b] = 1;
            if(t) return dp[i][t][b] = f(i+1,t^1,b);
            else return dp[i][t][b] = f(i+1,1,b) + f(i+1,0,b);
        };
        int ans = 0;
        
        std::function<int(int)> total = [&](int val){
            int ans = 0;
            for(int i=val-1;i>=1;i--) ans+=f(0,1,i);
            return ans+1;
        };
        bool flag = true;
        int cnt = 0;
        int prev_bit = 0;
        for(int i=tot_bits;i>=1;i--){
            int t = (1<<(i-1));
            if(num&t) {
                int tt=total(i);
                ans+=tt;
                if(prev_bit) return ans;
                prev_bit = 1;
                
            }
            else prev_bit = 0;
        }
        return ans+1;
    }
};