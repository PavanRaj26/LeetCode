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
    private:
    stack<TreeNode*> s1,s2;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        s1.push(root);
        while(!s1.empty() || !s2.empty()) {
            vector<int> tmp;
            if (!s1.empty()) {
                while(!s1.empty()) {
                    TreeNode* pp = s1.top();
                    s1.pop();
                    tmp.push_back(pp->val);
                    if (pp->left)
                    s2.push(pp->left);
                    if (pp->right)
                    s2.push(pp->right);
                }
                ans.push_back(tmp);
            }
            else {
             while(!s2.empty()) {
                    TreeNode* pp = s2.top();
                    s2.pop();
                    tmp.push_back(pp->val);
                    if (pp->right)
                    s1.push(pp->right);
                    if (pp->left)
                    s1.push(pp->left);
                }   
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
