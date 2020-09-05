class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        int left = 1, right = m*n;
        while(left<=right){
            int mid = left+(right-left)/2;
            int i = (mid+m-1)/m;
            int j;
            if(mid%m==0) j=m;
            else j=mid%m;
            i--,j--;
            int val = matrix[i][j];
            if(val==target) return true;
            else if(val<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return false;
    }
};