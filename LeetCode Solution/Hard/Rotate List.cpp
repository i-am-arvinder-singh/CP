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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(temp==NULL) return NULL;
        int n = 0;
        ListNode* last;
        if(temp->next==NULL) last = temp;
        while(temp!=NULL){
            n++;
            if(temp->next==NULL) last = temp;
            temp=temp->next;
        }
        k=k%n;
        if(k==0 || n==1 || n==0) return head;
        temp = head;
        ListNode* fu = temp;
        int times = k+1;
        while(times--){
            fu=fu->next;
        }
        // cout<<"**** "<<fu->val<<endl;
        ListNode* cur= head;
        while(fu!=NULL){
            cur=cur->next;
            fu=fu->next;
        }
        // cout<<"last: "<<last->val<<endl;
        ListNode *next_head = cur->next;
        cur->next=NULL;
        last->next=head;
        return next_head;
    }
};