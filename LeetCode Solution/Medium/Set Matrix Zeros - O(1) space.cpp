class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==0) return;
        int m = matrix[0].size();
        bool is_first_zero = false;
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0) is_first_zero = true;
        }
        // cout<<"1----> "<<is_first_zero<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;//Encoding all the information in first row.
                }
            }
        }
        //Starting from the second row
        for(int i=1;i<n;i++){
            bool isZero = false;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) isZero = true;
            }
            for(int j=0;j<m;j++){
                if(isZero || matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(is_first_zero){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
    }
};