class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        int left = 0, right = n-1;
        int mx = 0;
        int ans = 0;
        while(left<right){
            int l_val = height[left], r_val = height[right];
            int mn = min(l_val,r_val);
            if(l_val<r_val){
                if(l_val>mx){
                    mx=max(l_val,mx);
                    left++;
                }
                else{
                    ans+=(mx-l_val);
                    left++;
                }
            }
            else{
                if(r_val>mx){
                    mx=max(r_val,mx);
                    right--;
                }
                else{
                    ans+=(mx-r_val);
                    right--;
                }
            }
        }
        return ans;
    }
};