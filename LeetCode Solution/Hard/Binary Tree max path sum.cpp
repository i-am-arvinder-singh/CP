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
    int res = -1e9;
    int dfs(TreeNode* t)
    {
        if(t==NULL) return 0;
        int left = dfs(t->left), right = dfs(t->right);
        res=max({res,t->val+left+right});
        return max({0,max(left,right)+t->val});
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root);
        return res;
    }
    
};