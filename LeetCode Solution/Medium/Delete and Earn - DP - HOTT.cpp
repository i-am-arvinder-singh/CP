class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        map<int,int> my;
        
        for(auto ele:nums) my[ele]++;
        
        vector<int> v;
        for(auto &[x,y]:my) v.push_back(x);
        int n = v.size();
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        std::function<int(int,int)> f = [&](int i, int take){
            if(dp[i][take] != -1) return dp[i][take];
            if(i>=n) return dp[i][take] = 0;
            if(take){
                return dp[i][take] =  (my[v[i]]*v[i])+(i+1<n?(
                    (v[i+1]-v[i])==1?f(i+1,0):(
                        max(f(i+1,0),f(i+1,1))
                    )
                ):0);
            }
            else{
                return dp[i][take] = max(f(i+1,1),f(i+1,0));
            }
        };
        return max(f(0,0),f(0,1));
    }
};