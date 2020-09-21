/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp = head;
        ListNode *val = hasCycle(head);
        if(val!=NULL){
            ListNode *temp1 = head;
            ListNode *temp2 = val;
            while(temp1!=temp2){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1;
        }
        else return NULL;
        return NULL;
    }
    ListNode* hasCycle(ListNode *head)
    {
        if(head==NULL) return NULL;
        ListNode *slow = head;
        ListNode * fast = NULL;
        if(slow) fast = head->next;
        if(slow==fast) return slow;
        slow = slow->next;
        if(fast) fast = fast->next;
        while(slow!=fast && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return slow;
        }
        return NULL;
    }
};