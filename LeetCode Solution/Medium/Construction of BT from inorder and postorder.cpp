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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size()-1;
        return f(inorder, postorder,0,n,0,n);
    }
    TreeNode* f(vector<int> &inorder, vector<int> &postorder, int st_in, int en_in, int st_po, int en_po)
    {
        if(st_in>en_in || st_po>en_po) return NULL;
        TreeNode* temp = new TreeNode(postorder[en_po]);
        int ino_id;
        for(int i=st_in;i<=en_in;i++){
            if(inorder[i]==postorder[en_po]){
                ino_id=i;
                break;
            }
        }
        temp->left=f(inorder,postorder,st_in,ino_id-1,st_po,st_po+ino_id-1-st_in);
        temp->right=f(inorder,postorder,ino_id+1,en_in,st_po+ino_id-st_in,en_po-1);
        return temp;
    }
};