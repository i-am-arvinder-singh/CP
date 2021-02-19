#define ff first
#define ss second

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int mod = 1000000007;
        int n = nums.size();
        vector<int> left(n,1),right(n,1);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            int cnt = 1;
            while(!st.empty() && st.top().ff>=nums[i]){
                cnt+=st.top().ss;
                st.pop();
            }
            st.push({nums[i],cnt});
            left[i]=cnt;
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            int cnt = 1;
            while(!st.empty() && st.top().ff>nums[i]){
                cnt+=st.top().ss;
                st.pop();
            }
            st.push({nums[i],cnt});
            right[i]=cnt;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=(((long)nums[i]*((long)left[i]*right[i])%mod)%mod);
            ans%=mod;
        }
        return ans;
    }
};