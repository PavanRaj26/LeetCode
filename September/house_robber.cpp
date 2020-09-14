class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n,0);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i =1 ; i < n; i+=1) {
            dp[i]= nums[i];
            for (int j =0; j < i-1; j++) {
                dp[i] = max(dp[j] + nums[i],dp[i]);
            }
            ans = max(ans,dp[i]);
        }        
        return ans;
    }
};
