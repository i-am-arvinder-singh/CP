/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL ) return NULL;
        Node *temp = root, *nextHead=NULL, *prev=NULL;
        nextHead = root;
        while(nextHead){
            bool f = true;
            nextHead=NULL, prev=NULL;
            while(temp){
                if(f && temp->left) {
                    nextHead = temp->left;
                    prev = nextHead;
                    f = false;
                    if(temp->right){
                        prev -> next = temp -> right;
                        prev = temp->right;
                    }
                    temp = temp->next;
                }
                else if(f && temp->right){
                    nextHead = temp->right;
                    prev = nextHead;
                    f = false;
                    temp = temp->next;
                }
                else if(f) temp = temp->next;
                else{
                    if(temp->left){
                        prev->next = temp->left;
                        prev = temp->left;
                    }
                    if(temp->right){
                        prev -> next = temp -> right;
                        prev = temp->right;
                    }
                    temp = temp->next;
                }
            }
            temp = nextHead;
        }
        return root;
    }
};