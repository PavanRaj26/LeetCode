struct Node {
  int val;
  Node *left;
  Node *right;
};
vector<Node *> construct(int in[],int st,int end) {
    if (st > end) return res.push_back(NULL);
    vector<Node *> res;
    for (int i = st; i <= end; i++) {
        vector<Node *> tmp1 = construct(in,st,i-1);
        vector<Node *> tmp2 = construct(in,i+1,end);
        for (int j = 0;j < tmp1.size(); j++) {
            for (int k = 0; k < tmp2.size(); k++) {
                Node *left = tmp1[j];
                Node *right = tmp2[k];
                Node *nn = new Node();
                nn->left = left;
                nn->right = right;
                res.push_back(nn);
            }
        }
        
    }
    return res;
}