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
#define ff first
#define ss second
#define MP make_pair
class Solution {
    private:
    map<int,vector<pair<int,int> > > mp;
public:
    bool static comp(pair<int,int> &a,pair<int,int> &b) {
        
        if (a.ff > b.ff) {
            return true;
        }
        else if (a.ff < b.ff) {
            return false;
        }
        else {
            return a.ss < b.ss;
        }
        
        
    }
    void recur(TreeNode* root,int x,int y) {
        if (root == NULL) return;
        mp[x].push_back(MP(y,root->val));
        recur(root->left,x-1,y-1);
        recur(root->right,x+1,y-1);
        return;
    }
    vector<vector<int> >  verticalTraversal(TreeNode* root) {
        vector<vector<int> > ans;
        recur(root,0,0);
        map<int,vector<pair<int,int> > >::iterator it = mp.begin();
        for (;it!=mp.end(); it++) {
            vector<pair<int,int> > tmp = (*it).second;
            sort(tmp.begin(),tmp.end(),comp);            
            vector<int> tmp1;
            for (int i =0 ;i < tmp.size(); i++) {
                cout <<tmp[i].ff <<" "<<tmp[i].ss <<":";
                tmp1.push_back(tmp[i].ss);
            }
            cout <<endl;
            ans.push_back(tmp1);
        }
        return ans;
        
    }
};
