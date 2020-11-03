class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n==0||n==1) return;
        int i=0,j=n-1;
        while(i<n && nums[i]==0) i++;
        while(j>=0 && nums[j]==2) j--;
        int left = i, right = j;
        for(int k=left;k<=right && k<=j;k++){
            if(nums[k]==0){
                swap(nums[k],nums[i]);
                i++;
                while(i<n && nums[i]==0) i++;
                while(k<n && nums[k]==0) k++;
                k--;
                if(nums[k]==2 && k<=j){
                    swap(nums[k],nums[j]);
                    j--;
                    while(j>=0 && nums[j]==2) j--;
                }
            }
            else if(nums[k]==2){
                swap(nums[k],nums[j]);
                j--;
                while(j>=0 && nums[j]==2) j--;
                if(nums[k]==0 && k<=j){
                    swap(nums[k],nums[i]);
                    i++;
                    while(i<n && nums[i]==0) i++;
                    while(nums[k]==0 && k<n) k++;
                    k--;
                }
            }
        }
    }
};