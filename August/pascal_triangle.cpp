class Solution {
    int dp[34][34];
public:
    vector<int> getRow(int rowIndex) {
        dp[0][0] = 1;
        for (int i =1;i < 34; i++) {
            for (int j =0;j <= i; j++) {
                if (j) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else {
                    dp[i][0] = 1;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i <= rowIndex; i++) {
            ans.push_back(dp[rowIndex][i]);    
        }
        return ans;
    }
};
