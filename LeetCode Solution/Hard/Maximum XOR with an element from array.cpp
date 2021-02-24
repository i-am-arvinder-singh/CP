class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        //Author:omniphantom
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> v(31);
        for(int i=0;i<31;i++) {
            int t = (1<<i);
            for(int j=0;j<n;j++) {
                if(nums[j]&t) v[i].push_back(1);
                else          v[i].push_back(0);
            }
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++) {
            ans[i] = solve_queries(queries[i],v,nums);
        }
        return ans;
    }
    
    int solve_queries(vector<int> &q, vector<vector<int>> &v, vector<int> &nums) {
        int xor_val = q[0], m = q[1];
        auto it = lower_bound(nums.begin(),nums.end(),m);
        if(it==nums.begin()) {
            if(*it>m) return -1;
        }
        int range_min = 0, range_max = upper_bound(nums.begin(),nums.end(),m) - nums.begin() -1;
        int ans = 0;
        for(int i=30;i>=0;i--) {
            int and_val = (1<<i);
            int bit_val = (xor_val&and_val)?1:0;
            if(bit_val==0) {//Analyse the bit 1 part
                if(binary_search(v[i].begin()+range_min,v[i].begin()+range_max+1,1)) {
                    ans+=and_val;
                    int new_range_min = lower_bound(v[i].begin()+range_min,v[i].begin()+range_max+1,1) - (v[i].begin());
                    int new_range_max = range_max;
                    range_min=new_range_min;
                    range_max=new_range_max;
                }
            } else {//Analyse the bit 0 part
                if(binary_search(v[i].begin()+range_min,v[i].begin()+range_max+1,0)) {
                    ans+=and_val;
                    int new_range_min = range_min;
                    int new_range_max = upper_bound(v[i].begin()+range_min,v[i].begin()+range_max+1,0) - (v[i].begin())-1;
                    range_min=new_range_min;
                    range_max=new_range_max;
                }
            }
        }
        return ans;
    }
    
};