class Solution {
public:
    int findAns(vector<int> &nums){
        int n = nums.size();
        int cnt = 0;
        for(auto ele:nums){
            if(ele<0) cnt++;
        }
        if(cnt&1){
            if(n==1) return nums[0];
            vector<int> dp1(n),dp2(n);
            dp1[0] = abs(nums[0]);
            dp2[n-1] = abs(nums[n-1]);
            for(int i=1;i<n;i++) dp1[i]=dp1[i-1]*abs(nums[i]);
            for(int i=n-2;i>=0;i--) dp2[i]=dp2[i+1]*abs(nums[i]);
            int ans = nums[0];
            for(int i=0;i<n;i++){
                if(nums[i]<0){
                    if(0<i && i<n-1) ans=max({ans,dp1[i-1],dp2[i+1]});
                    else if(i==0) ans=max(ans,dp2[i+1]);
                    else if(i==n-1) ans=max(ans,dp1[i-1]);
                }
            }
            return ans;
        }
        else{
            int ans = 1;
            for(auto ele:nums) ans*=abs(ele);
            return ans;
        }
    }
    int maxProduct(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<vector<int>> w;
        bool flag = false;
        for(auto ele:nums) if(ele==0) flag=true;
        if(nums[i]!=0){
            vector<int> t;
            while(i<n && nums[i]!=0){
                t.push_back(nums[i]);
                i++;
            }
            if(t.size()!=0) w.push_back(t);
        }
        while(i<n){
            if(nums[i]==0){
                vector<int> t;
                int j = i+1;
                while(j<n && nums[j]!=0){
                    t.push_back(nums[j]);
                    j++;
                }
                i=j;
                if(t.size()!=0) w.push_back(t);
            }
        }
        int ans = nums[0];
        for(auto ele:w) ans=max(ans,findAns(ele));
        return flag?max(0,ans):ans;
    }
};










