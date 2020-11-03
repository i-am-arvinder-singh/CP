/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> v;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int n = v.size();
        return f(0,n-1);
    }
    TreeNode* f(int left, int right)
    {
        if(left>right) return NULL;
        TreeNode *temp;
        if(left<=right){
            int mid = left+(right-left)/2;
            temp = new TreeNode(v[mid]);
            temp->left = f(left,mid-1);
            temp->right = f(mid+1,right);
        }
        return temp;
    }
};










