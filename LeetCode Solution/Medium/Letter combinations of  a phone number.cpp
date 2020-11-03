class Solution {
public:
    vector<string> ans;
    unordered_map<char,string> my;
    int n;
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(n==0) return ans;
        my['2']="abc";
        my['3']="def";
        my['4']="ghi";
        my['5']="jkl";
        my['6']="mno";
        my['7']="pqrs";
        my['8']="tuv";
        my['9']="wxyz";
        string temp;
        f(digits,temp,0);
        return ans;
    }
    void f(string &digits, string temp, int id)
    {
        if(id==n){
            ans.push_back(temp);
            return;
        }
        for(auto ch:my[digits[id]]){
            f(digits,temp+ch,id+1);
        }
    }
};