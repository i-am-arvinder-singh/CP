class Solution {
    vector<vector<int>> ans;
    int n;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        n = candidates.size();
        if(n==0) return ans;
        f(candidates,target,path,0);
        return ans;
    }
    void f(vector<int> &candidates,int target, vector<int> &path, int i)
    {
        if(i==n) return;
        if(target<0) return;
        if(target==0){
            ans.push_back(path);
            return;
        }
        path.push_back(candidates[i]);
        f(candidates,target-candidates[i],path,i);
        path.pop_back();
        f(candidates,target,path,i+1);
    }
};