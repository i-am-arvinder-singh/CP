class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int bal = 0;
        int stars = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')      bal++;
            else if(s[i]==')') bal--;
            else stars++;
            if(bal==-1 && stars){
                bal++;
                stars--;
            } 
            else if(bal==-1){
                return false;
            }
        }
        bal=stars=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')')      bal++;
            else if(s[i]=='(') bal--;
            else stars++;
            if(bal==-1 && stars){
                bal++;
                stars--;
            } 
            else if(bal==-1){
                return false;
            }
        }
        return true;
    }
};