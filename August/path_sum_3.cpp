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
#define ll long long
class Solution {
    private: 
    int ans=0;
    ll key;
public:
    void sum_(TreeNode *root,ll sum) {
        
        if (root == NULL) {
            return ;    
        }
        if (root->val + sum == key) {
            ans++;
        }
        ll k1 = sum + root->val;
        ll k2 = sum + root->val;
        sum_(root->left,k1);
        sum_(root->right,k2);        
    }
    void recur(TreeNode *root) {
        int sum = 0;
        if (root == NULL) return;
        sum_(root,0);
        recur(root->left);
        recur(root->right);        
    }
    int pathSum(TreeNode* root, int sum) {
        key = sum;
        recur(root);
        return ans;
    }
};
