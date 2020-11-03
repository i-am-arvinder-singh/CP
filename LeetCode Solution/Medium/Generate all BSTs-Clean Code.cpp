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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            vector<TreeNode*> ans;
            return ans;
        }
        return generateTrees(1,n);
    }
    vector<TreeNode*> generateTrees(int left, int right)
    {
        vector<TreeNode*> ans;
        if(left>right){
            TreeNode* temp = NULL;
            ans.push_back(temp);
            return ans;
        }
        for(int i=left;i<=right;i++){
            vector<TreeNode*> leftSubtree = generateTrees(left,i-1);
            vector<TreeNode*> rightSubtree = generateTrees(i+1,right);
            for(auto ls : leftSubtree){
                for(auto rs : rightSubtree){
                    TreeNode *root = new TreeNode(i);
                    root->left=ls;
                    root->right=rs;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
