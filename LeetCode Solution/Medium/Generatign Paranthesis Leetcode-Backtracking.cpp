class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return ans;
        ans.clear();
        string temp;
        f(temp,n,n);
        return ans;
    }
    void f(string temp, int left, int right){
        if(left==0 && right==0){
            ans.push_back(temp);
            return;
        }
        if(left==right){
            return f(temp+"(",left-1,right);
        }
        else if(left<right){
            if(left>0) f(temp+"(",left-1,right);
            f(temp+")",left,right-1);
        }
    }
};