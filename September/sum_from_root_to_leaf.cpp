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
    int sum;
    void dfs(TreeNode *root,string bin) {
        
        string t(1,root->val + '0');
        string ind = bin + t;
        if (root->left == NULL && root->right == NULL) {
            reverse(ind.begin(),ind.end());
            int sz = ind.size();
            int ans = 0;
            int val = 1;
            for (int j =0; j < sz; j++) {
                if (ind[j] == '1') {
                    ans = ans + val;
                }
                val = val * 2;
            }
            cout << ans <<" ";
            sum = sum + ans;
            return ;
        }
        if (root->left) dfs(root->left,ind);
        if (root->right) dfs(root->right,ind);
        return ;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        if (root == NULL) {
            return 0;
        }
        dfs(root,"");
        return sum;
    }
};
