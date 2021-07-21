void kthLargestElement(Node *root) {
        Node *curr = root;
        int cnt = 1;
        while (curr) {
            if (curr->right) {
                Node *succ = curr->right;
                if (succ->left != NULL && succ->left != curr) {
                    succ=succ->left;
                }
                if (succ->left == NULL) {
                    
                    succ->left = curr;
                    curr = curr->right;
                } else {
                    if (cnt == K) {
                        return curr;
                    }
                    cnt++;
                    succ->left = NULL;
                    curr = curr->left;
                }
            } else {
                if (cnt == K) {
                    return curr;
                }
                cnt++;
                curr = curr->left;
            }
        }
        
    }