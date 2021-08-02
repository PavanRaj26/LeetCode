#include <stdio.h>

//Preorder
//Inorder

Node *findLca(Node *root,bool &v1,bool &v2,int k1,int k2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == k1) {
        v1 = true;
        return root;
    }
    if (root->val == k2) {
        v2 = true;
        return root;
    }
    Node *leftLca = findLca(root->left,v1,v2,k1,k2);
    Node *rightLca = findLca(root->right,v1,v2,k1,k2);
    if (leftLca != NULL && rightLca != NULL) return root;
    return (leftLca != NULL?leftLca : rightLca);
    
}
bool findLca(Node *root, int key1) {
    if (root == NULL) return false;
    if (root->val == key1) return true;
    if (findLca(root->left,key1) || findLca(root->right,key1)) {
        return true;
    }
    return false;
}
Node *getLca(Node *root) {

    bool v1,v2;
    Node *lca = findLca(root,v1,v2,key1,key2);
    if (v1 && v2) {
        return lca;
    }
    if (!v1 && find(root,key2)) {
        return lca;
    }
    if (!v2 && find(root,key1)) {
        return lca;
    }
    return NULL;
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