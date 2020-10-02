class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
    vector< vector< vector< vector<int> > > > dp(32,vector<vector<vector<int> > >(502));
        int n = a.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= target; j++) {                
                
                vector< vector<int> > res;                
                if (i) {
                    res.insert(res.end(),dp[i-1][j].begin(),dp[i-1][j].end());
                }
                if (j >= a[i]) {       
                    vector<vector<int> > tmp1 = dp[i][j-a[i]];                    
                    if (j != a[i]) {
                        for (int ii = 0;ii < tmp1.size(); ii++) {
                            vector<int> tmp;
                            tmp.insert(tmp.end(),tmp1[ii].begin(),tmp1[ii].end());
                            tmp.push_back(a[i]);
                            res.push_back(tmp);
                        }
                    } else {
                      vector<int> tmp;
                      tmp.push_back(a[i]);
                      res.push_back(tmp);
                    }                    
                }   
                dp[i][j] = res;
            }    
        }
        return dp[n-1][target];
    }
};
