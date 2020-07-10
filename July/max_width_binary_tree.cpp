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
    unordered_map<int,int> mp;
    int ans = 0;
public:
    void recur(TreeNode *root,int depth,int pos) {
        if (root == NULL) return;
        if (mp.find(depth) == mp.end()) {
            mp[depth] = pos;
        }
        ans = max(ans,pos-mp[depth] + 1);
        int posL = 2 * 1ll * pos;
        int posR = 2 * 1ll * pos + 1;
        
        recur(root->left,depth+1,posL);
        recur(root->right,depth+1,posR);
        return ;
    }
    int widthOfBinaryTree(TreeNode* root) {
           
        if (root == NULL) return 0;
        recur(root,0,0);
       
        return ans;
    }
};
