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
    private :
    int sum=0;
public:
    void recur(TreeNode *root) {
        if (root == NULL)return;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL ) {
            sum = sum + root->left->val;
        }
        recur(root->left);
        recur(root->right);        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        recur(root);
        return sum;
    }
};
