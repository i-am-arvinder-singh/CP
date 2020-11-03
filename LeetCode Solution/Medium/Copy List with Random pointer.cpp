/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node *temp = head;
        map<Node*,Node*> my;
        Node *new_head = new Node(temp->val);
        my[head]=new_head;
        temp=temp->next;
        Node *prev = new_head;
        while(temp){
            Node *new_node = new Node(temp->val);
            my[temp] = new_node;
            prev->next = new_node;
            prev = new_node;
            temp = temp->next;
        }
        temp = head;
        while(temp){
            my[temp]->random = my[temp->random];
            temp = temp->next;
        }
        return new_head;
    }
};