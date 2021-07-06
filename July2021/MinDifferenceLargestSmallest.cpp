class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        } else {
            sort(nums.begin(),nums.end());
            int ans = min(nums[n-3]-nums[1],nums[n-2] - nums[2]);
            if (n == 5) {
                for (int i = 1; i < n; i++) {
                    ans = min(ans,nums[i]-nums[i-1]);
                }
            }
            ans = min(ans,nums[n-4]-nums[0]);
            ans = min(ans,nums[n-1]-nums[3]);
            return ans;
        }
    }
};