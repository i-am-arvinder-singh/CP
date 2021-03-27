/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        
        
        vector<TreeNode*> ans;
        if((n&1)==0) return ans;
        if(n==1){
            TreeNode* temp = new TreeNode(0);
            ans.push_back(temp);
            return ans;
        }
        
        int t = 1;
        
        unordered_map<int,vector<TreeNode*>> my;
        
        while(n-t>=1){
            my[n-t]=(allPossibleFBT(n-t));
            t++;
        }
        
        int w = n-1;
        
        for(int k=1;k<w;k+=2){
            for(auto val1:my[k]){
                for(auto val2:my[w-k]){
                    // cout<<"####"<<endl;
                    TreeNode* temp = new TreeNode(0);
                    
                    temp->left = val1;
                    temp->right = val2;
                    
                    ans.push_back(temp);
                    
                }
            }
        }
        
        return ans;
        
        
        
    }
};






