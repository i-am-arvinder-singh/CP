#define mod 1000000007

class Solution {
    int add(int x, int y){
        x%=mod;
        y%=mod;
        return (x+y)%mod;
    }
    int mul(int x, int y){
        x%=mod;
        y%=mod;
        long long ans = (long long)x * (long long)y;
        return ans%mod;
    }
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<int>> dp(n+3,vector<int>(k+3,-1));
        std::function<int(int,int)> f = [&](int n_, int k_){
            if(dp[n_][k_]!=-1) return dp[n_][k_];
            if(n_<0 || k_<0) return 0;
            if(k_==0 && n_>0) return dp[n_][k_] = 0;
            if(k_>n_) return dp[n_][k_] = 0;
            if(k_==n_) return dp[n_][k_] = 1;
            int ans = f(n_-1,k_-1);
            // if(ans<0) cout<<"***** "<<n_<<" "<<k_<<endl;
            ans=add(ans,mul((n_-1),f(n_-1,k_)));
            return dp[n_][k_] = ans;
        };
        return f(n,k);
    }
};