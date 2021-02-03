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
    map<int,int> my;
public:
    void f(TreeNode* root,int level){
        my[level]=root->val;
        // cout<<root->val<<" ";
        if(root->left) f(root->left,level+1);
        if(root->right) f(root->right,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        f(root,0);
        for(auto &[x,y]:my) v.push_back(y);
        return v;
    }
};