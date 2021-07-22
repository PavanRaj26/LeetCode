struct Node {
    int val;
    Node *left;
    Node *right;
};
unordered_map<Node *, Node *> mp;
Node* recur(Node *root) {
    if (root == NULL) return;
    Node *nn = (struct Node *) malloc(sizeof(struct Node));
    mp[root] = nn;
    nn->val = root->val;
    nn->left = recur(root->left);
    nn->right = recur(root->right);
    
    return nn;
}
void cloneRandom(Node *root,Node *clone) {
    
    if (root == NULL) return;
    clone->random = mp[root->random];
    cloneRandom(root->left,clone->left);
    cloneRandom(root->right,clone->right);
    return;
}
Node *cloneEntire(Node *root) {
    
    //Fill map 
    Node *clone = recur(root);
    cloneRandom(root,clone);    
}
int main() {
	//code
	//Construct Tree;
	
	Node* clone = cloneEntire(root);
	return clone;
}