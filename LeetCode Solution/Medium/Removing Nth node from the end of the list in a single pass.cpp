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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head, *prev=NULL, *cur=head, *adv=head;
        if(head==NULL) return head;
        int cnt = 0;
        while(adv!=NULL){
            adv=adv->next;
            cnt++;
            if(cnt==n) break;
        }
        while(adv!=NULL){
            adv=adv->next;
            prev=cur;
            cur=cur->next;
        }
        if(cur==first){
            head=head->next;
            return head;
        }
        prev->next=cur->next;
        return head;
    }
};