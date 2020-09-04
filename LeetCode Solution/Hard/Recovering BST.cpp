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
    vector<pair<int,TreeNode*>> order;
public:
    void recoverTree(TreeNode* root) {
        f(root);
        int n = order.size();
        if(n==1) return;
        if(n==2){
            if(order[0].first<order[0].first) return;
            else{
                swap(order[0].second->val,order[1].second->val);
            }
            return;
        }
        bool flag1 = true, flag2 = true;;
        int id1, id2;
        for(int i=0;i<n-1;i++){
            if(flag1 && order[i].first>order[i+1].first){
                id1=i;
                flag1=false;
            }
            else if(order[i].first>order[i+1].first){
                id2=i+1;
                flag2=false;
            }
        }
        if(flag1==false && flag2==true){
            swap(order[id1].second->val,order[id1+1].second->val);
        }
        else{
            swap(order[id1].second->val,order[id2].second->val);
        }
    }
    void f(TreeNode* root)
    {
        if(root==NULL) return;
        f(root->left);
        order.push_back({root->val,root});
        f(root->right);
    }
};