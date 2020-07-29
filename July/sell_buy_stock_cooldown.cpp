class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        if (n == 0) return 0;
        vector<int> dp(n,0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1;j < n; j++) {
                if (j + 2 < n)
                    dp[i] = max(dp[i],a[j] - a[i] + dp[j + 2]);
                else if (j < n){
                    dp[i] = max(dp[i],a[j] - a[i]);
                }
            }
            if (i < n-1)
            dp[i] = max(dp[i],dp[i+1]);
        }
        
    return dp[0];
    }
};
