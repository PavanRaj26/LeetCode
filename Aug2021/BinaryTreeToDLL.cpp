#include <stdio.h>

//Preorder
//Inorder

Node *construct(Node *root) {
    
    if (root->left) {
        Node *left = construct(root->left);
        for (; left->right != NULL; left = left->right) {
        }
        left->right = root;
        root->left = left;
    }
    if (root->right) {
        Node *right = construct(root->right);
        for (; right->left != NULL; right = right->left) {}
        right->left = root;
        root->right = right;
    }
    return root;
}
void recur(Node *root, Node **head) {
    static Node *prev=NULL;
    recur(root->left,head);
    if (prev == NULL) {
        *head = root;
    }
    else {
        root->left = prev;
        prev->right = root; 
    }
    prev = root;
    recur(root->right,head);
}
int main() {
	//code
	
	return 0;
}