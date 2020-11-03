/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        vector<Node*> vis(1000,NULL);
        Node *newnode = new Node(node->val);
        vis[newnode->val]=newnode;
        for(auto child_node : node->neighbors){
            if(vis[child_node->val]==NULL){
                Node *new_child_node = new Node(child_node->val);
                (newnode->neighbors).push_back(new_child_node);
                dfs(new_child_node,child_node,vis);
            }
            else (newnode->neighbors).push_back(vis[child_node->val]);
        }
        return newnode;
    }
    
    void dfs(Node* current, Node* original_node, vector<Node*> &vis)
    {
        vis[current->val]=current;
        for(auto child_node:original_node->neighbors){
            if(vis[child_node->val]==NULL){
                Node *new_child_node = new Node(child_node->val);
                (current->neighbors).push_back(new_child_node);
                dfs(new_child_node,child_node,vis);
            }
            else (current->neighbors).push_back(vis[child_node->val]);
        }
    }
};












