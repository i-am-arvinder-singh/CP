class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int max_el) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            vector<int> row(n);
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++) row[k]+=matrix[k][j];
                vector<int> dp(n);
                dp[0]=row[0];
                for(int i=1;i<n;i++) dp[i]=max(row[i],dp[i-1]+row[i]);
                int mx = INT_MIN;
                vector<int> pref_sum;
                int sum = 0;
                for(int k=0;k<n;k++){
                    sum+=row[k];
                    pref_sum.push_back(sum);
                    if(dp[k]>=mx){
                        mx=dp[k];
                    }
                }
                if(mx<=max_el){
                    ans=max(ans,mx);
                    continue;
                }
                set<int> s = {0};
                sum = 0;
                for(int k=0;k<n;k++){
                    sum+=row[k];
                    auto it = s.lower_bound(sum-max_el);
                    if(it!=s.end()){
                        ans=max(ans,sum-(*it));
                    }
                    s.insert(pref_sum[k]);
                }
            }
        }
        return ans;
    }
};




