class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool f = false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                f=true;
            }
        }
        if(f==false){
            return 1;
        }
        for(int i=0;i<n;i++){
            if(1<=nums[i] && nums[i]<=n){
                continue;
            }
            else{
                nums[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            }
        }
        int i=0;
        for(i=0;i<n;i++){
            if(nums[i]<0) continue;
            else return i+1;
        }
        return n+1;
    }
};