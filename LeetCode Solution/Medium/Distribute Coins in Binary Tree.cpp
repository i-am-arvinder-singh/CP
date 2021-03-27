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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        std::function<int(TreeNode*)> dfs = [&](TreeNode* root){
            if(root==NULL) return 0;
            int coins = 0;
            int coins1=dfs(root->left);
            int coins2=dfs(root->right);
            ans+=(abs(coins1)+abs(coins2));
            return coins1+coins2+root->val-1;
        };
        dfs(root);
        return ans;
    }
};