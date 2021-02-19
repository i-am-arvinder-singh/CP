class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        int mn = 1e9;
        int mx = -1e9;
        for(int i=0;i<n;i++) mx=max(mx,nums[i]),mn=min(mn,nums[i]);
        int avg = (mx-mn+n-2)/(n-1);
        if(avg==0) avg++;
        int b = (mx-mn+avg-1)/avg;
        b++;
        vector<int> minBuck(b,1e9),maxBuck(b,-1e9);
        for(int i=0;i<n;i++){
            int buck = (nums[i]-mn)/avg;
            minBuck[buck]=min(minBuck[buck],nums[i]);
            maxBuck[buck]=max(maxBuck[buck],nums[i]);
        }
        int i=0;
        int ans = 0;
        while(i<b && minBuck[i]==1e9) i++;
        int j = i+1;
        while(j<b){
            if(minBuck[j]!=1e9){
                ans=max(minBuck[j]-maxBuck[i],ans);
                i=j;
                j=i+1;
            }
            else j++; 
        }
        return ans;
    }
};
