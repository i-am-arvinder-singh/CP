class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int left = matrix[0][0], right = matrix[n-1][m-1];
        
        std::function<int(int)> cnt = [&](int mid){
            int count = 0;
            for(int i=0;i<n;i++){
                auto c = upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
                count+=c;
            }
            return count;
        };
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(cnt(mid)<k) left = mid+1;
            else{
                right = mid;
            }
        }
        
        return left;
        
    }
};