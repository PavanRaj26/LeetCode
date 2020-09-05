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
    vector<int> ans;
    
public:
    void recur(TreeNode *root) {
        if (root == NULL) {
            return ;
        }
        ans.push_back(root->val);
        recur(root->left);
        recur(root->right);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        recur(root1);
        recur(root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
