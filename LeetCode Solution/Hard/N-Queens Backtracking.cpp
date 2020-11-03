class Solution {
    vector<vector<string>> ans;
    string t;
    int n;
public:
    vector<vector<string>> solveNQueens(int w) {
        n=w;
        if(n==0) return ans;
        for(int i=0;i<n;i++) t+='.';
        vector<int> col(n,-1);
        f(0,col);
        return ans;
    }
    void f(int row,vector<int> &col)
    {
        if(row==n){
            vector<string> res(n,t);
            for(int i=0;i<n;i++){
                res[col[i]][i]='Q';
            }
            ans.push_back(res);
            return;
        }
        for(int i=0;i<n;i++){
            if(col[i]==-1 && isOk(col,i,row)){
                col[i]=row;
                f(row+1,col);
                col[i]=-1;
            }
        }
    }
    bool isOk(vector<int> col, int pos, int row)
    {
        for(int i=0;i<n;i++){
            if(i==pos || col[i]==-1) continue;
            if(abs(i-pos)==abs(col[i]-row)) return false;
        }
        return true;
    }
};