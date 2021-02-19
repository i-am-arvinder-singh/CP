class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        srand ( time(NULL) );
        std::function<int(int,int)> f = [&](int first, int last){
            int RandIndex = rand()%(last-first+1);
            int pivot_id = first+RandIndex;
            int i = first-1, j = first;
            bool flag = false;
            while(j<=last){
                if(j==pivot_id){
                    j++;
                    continue;
                }
                if(nums[j]>nums[pivot_id]){
                    j++;
                }
                else{
                    if(i+1==pivot_id){
                        flag = true;
                        i++;
                    }
                    swap(nums[i+1],nums[j]);
                    i++;
                    j++;
                }
            }
            if(flag) swap(nums[i],nums[pivot_id]);
            else swap(nums[i+1],nums[pivot_id]);
            return flag?i:i+1;
        };
        // cout<<f(0,n-1)<<endl;
        // for(auto ele:nums) cout<<ele<<" ";
        // cout<<endl;
        int left = 0, right = n-1;
        while(true){
            int cur = f(left,right);
            int cur_pos = n - cur;
            if(cur_pos==k) return nums[cur];
            if(cur_pos>k) left = cur+1;
            else right = cur-1;
        }
        return 0;
    }
};