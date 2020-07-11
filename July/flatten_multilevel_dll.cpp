/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    private:
    Node* top;
    Node *head;
public:
    void recur(Node *root) {
        if (root == NULL) return;
        
        Node *nxt = root->next;
        Node *child = root->child;
        if (child) {
            root->child=NULL;
            child->prev = root;
            root->next = child;
            head = child;
            recur(head);
        }
        if (head) {
            head ->next = nxt;         
        }
        if (nxt) {
            nxt->prev = head;
            head = head->next;
            recur(head);
        }
        return;
    }
    Node* flatten(Node* root) {
        head = root;
        recur(root);
        return root;    
    }
};
