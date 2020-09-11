class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int mx = nums[0];
        int mn = nums[0];
        int msf = nums[0];
        for(int i =1; i < n; i++) {
            int a = mx * nums[i];
            int b = mn * nums[i];
            mx = max(max(a,b),nums[i]);
            mn = min(min(a,b),nums[i]);
            msf = max(msf,mx);
        }
       return msf;
    }
};
