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
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL) return;
        ListNode *temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        int upto = (n+1)/2;
        temp = head;
        upto--;
        while(upto--){
            temp = temp -> next;
        }
        ListNode *nexthead = temp->next;
        temp->next = NULL;
        nexthead = reverseList(nexthead);
        //head and nexthead
        ListNode *temp1 = head;
        ListNode *temp2 = nexthead;
        ListNode *prev1 = temp1;
        ListNode *prev2 = temp2;
        while(prev1 && prev2){
            temp1 = temp1->next;
            temp2 = temp2->next;
            prev1->next = prev2;
            prev2->next = temp1;
            prev1 = temp1;
            prev2 = temp2;
        }
    }
    ListNode* reverseList(ListNode *root)
    {
        if(root==NULL) return NULL;
        ListNode *prev=NULL, *cur=NULL, *fu=NULL;
        prev = root;
        cur = root->next;
        prev->next = NULL;
        if(cur) fu = cur->next;
        while(cur){
            cur->next = prev;
            prev = cur;
            cur = fu;
            if(cur) fu = cur->next;
        }
        return prev;
    }
};




