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
    bool recur(TreeNode* r1,TreeNode* r2) {
        if (r1 == NULL && r2 == NULL) return true;
        if (r1 == NULL) return false;
        if (r2 == NULL) return false;
        if (r1->val == r2->val && recur(r1->left,r2->left) && recur(r1->right,r2->right))
            return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return recur(p,q);   
    }
};
