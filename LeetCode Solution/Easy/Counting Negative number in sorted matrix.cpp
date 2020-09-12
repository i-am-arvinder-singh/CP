class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        if(m==0) return 0;
        int cnt = 0;
        int j=m;
        for(int i=0;i<n;i++){
            while(j-1>=0 && grid[i][j-1]<0) j--;
            cnt+=(m-j);
        }
        return cnt;
    }
};