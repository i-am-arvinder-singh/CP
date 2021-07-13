class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        int cur = 0;
        long long ans = 0;
        vector<int> dp(1024);
        dp[0]=1;
        for(int i=0;i<n;i++){
            int shif = (word[i]-'a');
            cur^=(1<<shif);
            ans+=dp[cur];
            for(int j=0;j<10;j++)
                ans+=dp[cur^(1<<j)];
            dp[cur]++;
        }
        return ans;
    }
};