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
    int idx;
public:
    TreeNode* recur(vector<int> &a,vector<int>& b,int st,int end) {
        if (st > end) return NULL;
        if (idx < 0) return NULL;
        int mid = mp[b[idx]];
        TreeNode * root = new TreeNode();
        root->val = b[idx];
        idx--;        
        root->right = recur(a,b,mid+1,end);
        root->left = recur(a,b,st,mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& a, vector<int>& b) {
        int n = a.size();
        if (n == 0) return NULL;
        for (int i = 0; i < n; i++) {
            mp[a[i]] = i;
        }
        idx = n-1;
        return recur(a,b,0,n-1);
    }
};
