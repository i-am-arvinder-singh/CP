class Solution {
    int target;
    int n;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n= nums.size();
        int sum = 0;
        for(auto ele:nums) sum+=ele;
        if(sum%k) return false;
        target = sum/k;
        vector<int> dp(1<<n,-1);
        srand(time(NULL));
        std::function<int(int,int)> getHash = [&](int x, int y){
            return (x<<16)^y;
        };
        unordered_map<int,int> my;
        std::function<int(int,int)> f = [&](int cur_sum, int vis){
            if(my.find(getHash(cur_sum,vis))!=my.end()) return my[getHash(cur_sum,vis)];
            if(vis==((1<<n)-1)) {
                if(cur_sum==0) return my[getHash(cur_sum,vis)] = 1;
                else return my[getHash(cur_sum,vis)] = 0;
            }
            else if(cur_sum==0) {
                return my[getHash(cur_sum,vis)] = f(target,vis);
            }
            for(int i=0;i<n;i++){
                int now = (1<<i);
                if((vis&now)==0){
                    vis^=now;
                    bool t = false;
                    if(cur_sum-nums[i]>=0)
                        t = f(cur_sum-nums[i], vis);
                    vis^=now;
                    if(t) return my[getHash(cur_sum,vis)] = (int)t;
                }
            }
            return my[getHash(cur_sum,vis)] = 0;
        };
        int vis = 0;
        return f(target,vis);
    }
};