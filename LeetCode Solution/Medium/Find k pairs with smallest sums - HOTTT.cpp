class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        
        auto cmp = [&](auto &p1, auto &p2){
            return nums1[p1.first]+nums2[p1.second] > nums1[p2.first]+nums2[p2.second];
        };
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        
        pq.push({0,0});
        k=min(k,n*m);
        // vector<vector<int>> ans;
        unordered_map<long long,bool> my;
        
        std::function<int(int,int)> hash = [&](int x, int y){
            return ((long long)(x + y)*(long long)(x + y + 1)/2) + y;
        };
        
        while(k--){
            auto idx_pair = pq.top();
            int i = idx_pair.first, j = idx_pair.second;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<n) pq.push({i+1,j});
            if(i==0 && j+1<m) pq.push({i,j+1});
            // if(i+1<n) {
            //     if(!my[hash(i+1,j)]){
            //         pq.push({i+1,j});
            //         my[hash(i+1,j)]=true;
            //     }
            // }
            // if(j+1<m) {
            //     if(!my[hash(i,j+1)]){
            //         pq.push({i,j+1});
            //         my[hash(i,j+1)]=true;
            //     }
            // }
        }
        return ans;
    }
};