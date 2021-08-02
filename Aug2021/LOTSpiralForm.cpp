#include <stdio.h>

//Preorder
//Inorder
void recur(Node *root) {
    stack<Node *> s1,s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        
        while (!s1.empty()) {
            Node *nn = s1.top();s1.pop();
            if (nn->right) s2.push(nn->right);
            if (nn->left) s2.push(nn->left);
        }
        while (!s2.empty()) {
            Node *nn = s2.top();s2.pop();
            if (nn->left) s1.push(nn->left);
            if (nn->right) s1.push(nn->right);
        }
    }
}

int main() {
	//code
	
	return 0;
}