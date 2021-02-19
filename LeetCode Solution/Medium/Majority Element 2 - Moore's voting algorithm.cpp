class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==0) return ans;
        else if(nums.size()==1){
            ans.push_back(nums[0]);
            return ans;
        }
        int n = nums.size();
        int ele1 = 1, ele2 = 1;
        int ele1_cnt = 0, ele2_cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1){
                ele1_cnt++;
            }
            else if(nums[i]==ele2){
                ele2_cnt++;
            }
            else if(ele1_cnt==0){
                ele1=nums[i];
                ele1_cnt = 1;
            }
            else if(ele2_cnt==0){
                ele2=nums[i];
                ele2_cnt = 1;
            }
            else{
                ele1_cnt--;
                ele2_cnt--;
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) cnt++;
        }
        if(cnt>(n/3)) ans.push_back(ele1);
        cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele2) cnt++;
        }
        if(cnt>(n/3)) ans.push_back(ele2);
        return ans;
    }
};