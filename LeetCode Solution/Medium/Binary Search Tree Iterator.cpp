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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        st.push(root);
        while(root->left){
            st.push(root->left);
            root=root->left;
        }
    }
    
    int next() {
        int ans = st.top()->val;
        TreeNode* cur = st.top();
        st.pop();
        if(cur->right){
            cur=cur->right;            
            while(cur->left){
                st.push(cur);
                cur=cur->left;
            }
            st.push(cur);
        }
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */