class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int t1 = nums[i];
                int t2 = nums[j];
                if(t1==0 || t2==0) // Take care of this TC
                    continue;
                if(t2>t1){
                    int up = t2 + t1;
                    int down = t2 - t1;
                    auto it1 = upper_bound(nums.begin(),nums.end(),down) - nums.begin();
                    auto it2 = upper_bound(nums.begin(),nums.end(),up-1);
                    it2--;
                    int id2 = it2 - nums.begin();
                    int t = id2 - it1 + 1;
                    if(it1<=i && i<=id2)
                        t--;
                    if(it1<=j && j<=id2)
                        t--;
                    ans+=t;
                }
                else{
                    int down = t1 - t2;
                    int up = t2 + t1;
                    auto it1 = upper_bound(nums.begin(),nums.end(),down) - nums.begin();
                    auto it2 = upper_bound(nums.begin(),nums.end(),up-1);
                    it2--;
                    int id2 = it2 - nums.begin();
                    int t = id2 - it1 + 1;
                    if(it1<=i && i<=id2)
                        t--;
                    if(it1<=j && j<=id2)
                        t--;
                    ans+=t;
                }
            }
        }
        return ans/3;
    }
};