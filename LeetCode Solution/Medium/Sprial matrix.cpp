class Solution {
    vector<int> ans;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==0) return ans;
        int m = matrix[0].size();
        if(m==0) return ans;
        int x = (n+1)/2, y=(m+1)/2;
        int cnt = n*m;
        for(int j=0,k=0;j<x && k<y;j++,k++){
            for(int i=k;i<m-k;i++){
                ans.push_back(matrix[j][i]);
                cnt--;
                if(cnt==0) break;
            }
            if(cnt==0) break;
            for(int i=1+j;i<n-j;i++){
                ans.push_back(matrix[i][m-1-k]);
                cnt--;
                if(cnt==0) break;
            }
            if(cnt==0) break;
            for(int i=m-2-j;i>=j;i--){
                ans.push_back(matrix[n-1-j][i]);
                cnt--;
                if(cnt==0) break;
            }
            if(cnt==0) break;
            for(int i=n-2-k;i>=1+k;i--){
                ans.push_back(matrix[i][k]);
                cnt--;
                if(cnt==0) break;
            }
            if(cnt==0) break;
        }
        return ans;
    }
};