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
    void flatten(TreeNode* root) {
        if(root==NULL ||(root->left==NULL && root->right==NULL)) return;
        //Apply flatten logic recursively
        if(root->left){
            flatten(root->left);
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *cur = root->right;
            while(cur->right){
                cur=cur->right;
            }
            cur->right = temp;
        }
        if(root->right){
            flatten(root->right);
        }
        // return root;
    }
};