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
#define pb push_back
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        auto goToDepth = [&](TreeNode *temp){
            if(temp==NULL) return;
            st.push(temp);
            while(temp->left || temp->right){
                if(temp->left){
                    temp = temp -> left;
                    st.push(temp);
                }
                else if(temp->right){
                    temp = temp -> right;
                    st.push(temp);
                }
            }
        };
        goToDepth(root);
        vector<int> ans;
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            ans.pb(temp->val);
            if(!st.empty() && st.top()->right){
                if(temp==st.top()->right) continue;
                else{
                    goToDepth(st.top()->right);
                }
            }
        }
        return ans;
    }
};


