class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 1;
        int n = preorder.size();
        for(int i=0;i<n;i++){
            if(preorder[i]==',') count--;
            if(count<0) return false;
            if(preorder[i]==',' && preorder[i-1]!='#') count+=2;
        }
        count--;
        if(preorder[n-1]!='#') count+=2;
        return count==0;
    }
};