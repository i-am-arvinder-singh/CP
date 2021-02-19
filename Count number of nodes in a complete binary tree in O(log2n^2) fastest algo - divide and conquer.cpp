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
    int findHeight(TreeNode* root){//root cannot be null
        if(root->left) return 1+findHeight(root->left);
        else return 0;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int height = findHeight(root);
        if(!root->left) return 1;
        else if(!root->right){
            return 2;
        }
        else{
            int treeHeight = findHeight(root);
            int subLeftHeight = findHeight(root->left);
            int subRightHeight = findHeight(root->right);
            if(subLeftHeight==subRightHeight){
                return (1<<(subLeftHeight+1)) + countNodes(root->right);
            } else {
                return (1<<(subRightHeight+1)) + countNodes(root->left);
            }
        }
    }
};