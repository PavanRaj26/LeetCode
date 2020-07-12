class Solution {
    private:
    vector< vector<int> > ans;
public:
    vector<vector<int>> subsets(vector<int>& a) {
            int n = a.size();
        
        if (n == 0) {
            ans.push_back(vector<int>(0));
            return ans;            
        }
        for (int i = 0; i < (1<<n); i++) {
            vector<int> tmp;
            for (int j= 0;j < n; j++) {
                if (i & ( 1<<j)) {
                    tmp.push_back(a[j]);
                }
            }
            sort(tmp.begin(),tmp.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};
