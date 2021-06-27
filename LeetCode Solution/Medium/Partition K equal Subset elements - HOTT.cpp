class Solution {
    int target;
    int n;
    
    // bool f(int i, int left, int cur_sum, vector<bool> vis, vector<int> &nums){
    //         if(left==1) return true;
    //         if(cur_sum==target) return f(0,left-1,0,vis,nums);
    //         for(int i=0;i<n;i++){
    //             if(!vis[i]){
    //                 vis[i]=1;
    //                 // bool t = false;
    //                 // if(cur_sum<=target)
    //                     // t = f(i+1,left,cur_sum+nums[i], vis);
    //                 if(f(i+1,left,cur_sum+nums[i], vis,nums)) return true;
    //                 vis[i]=0;
    //             }
    //         }
    //         return false;
    //     };

    // bool dfs(vector<int>& nums,vector<bool>visited,int idx,int k,int currsum,int targetsum)
    // {
    //     if(k==1) return true;                                               
    //     if(currsum==targetsum) return dfs(nums,visited,0,k-1,0,targetsum); 
    //     for(int i=idx ; i<nums.size() ; i++)
    //     {
    //         if(!visited[i])                       
    //         {
    //             visited[i]=true;                                                         
    //             if(dfs(nums,visited,i+1,k,currsum+nums[i],targetsum)) return true;        
    //             visited[i]=false;                                                         
    //         }
    //     }
    //     return false;
    // }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n= nums.size();
        int sum = 0;
        for(auto ele:nums) sum+=ele;
        if(sum%k) return false;
        target = sum/k;
        
        std::function<bool(int,int,int,vector<bool>&)> f = [&](int id, int left, int cur_sum, vector<bool> &vis){
            if(left==1) return true;
            if(cur_sum==target) return f(0,left-1,0,vis);
            for(int i=id;i<n;i++){
                if(!vis[i]){
                    vis[i]=1;
                    bool t = false;
                    if(cur_sum<=target)
                        t = f(i+1,left,cur_sum+nums[i], vis);
                    if(t) return t;
                    // if(f(i+1,left,cur_sum+nums[i], vis)) return true;
                    vis[i]=0;
                }
            }
            return false;
        };
        
        vector<bool> w(n);
        return f(0,k,0,w);
        // return dfs(nums,w,0,k,0,target);
    }
};