class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp={0};
        while(dp.size()<=n){
            int t = dp.size();
            int val = INT_MAX;
            for(int j=1;j*j<=t;j++) val=min(val,1+dp[t-(j*j)]);
            dp.push_back(val);
        }
        return dp[n];
    }
};