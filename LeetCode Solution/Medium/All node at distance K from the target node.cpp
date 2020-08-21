/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> par;
    unordered_map<TreeNode*,bool> vis;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(K==0){
            int d = target->val;
            vector<int> v;
            v.push_back(d);
            return v;
        }
        traverse(root,NULL);
        queue<TreeNode*> q;
        q.push(target);
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                vis[node]=true;
                q.pop();
                // cout<<cnt<<"*** "<<" "<<node->val<<endl;
                if(node->left !=NULL && !vis[node->left]) q.push(node->left);
                if(node->right!=NULL && !vis[node->right]) q.push(node->right);
                if(par[node]  !=NULL && !vis[par[node]]) q.push(par[node]);
            }
            cnt++;
            if(cnt==K) break;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
    void traverse(TreeNode* root,TreeNode* parent){
        if(root==NULL) return;
        vis[root]=false;
        par[root]=parent;
        // if(par[root]!=NULL)
            // cout<<"**** "<<par[root]->val<<endl;
        traverse(root->left,root);
        traverse(root->right,root);
    }
};