/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int> > v;
        if (root == NULL) return v;
        Q.push(root);
        while(!Q.empty()) {
            int cnt = Q.size();
            vector<int> tmp;
            while(cnt) {
                TreeNode *fr = Q.front();
                Q.pop();
                tmp.push_back(fr->val);
                if (fr->left != NULL){
                    Q.push(fr->left);
                }
                if (fr->right != NULL) {
                    Q.push(fr->right);
                }
                cnt--;
            }
            v.push_back(tmp);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
