class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<int> mx(n,0);
        vector<int> mn(n,0);
        if (n == 1 || n == 0) {
            return 0;
        }
        mn[0] = a[0];
        mx[n-1] = a[n-1];
        for (int i =1; i < n;i++) {
            mn[i] = min(mn[i-1],a[i]);
        }
        int ans = mx[n-1] - mn[n-2];
        for (int i = n - 2; i >= 0; i--) {
            mx[i] = max(mx[i+1],a[i]);
            if (i)
                ans = max(ans,mx[i] - mn[i-1]);
                        
        }
        if (ans < 0) ans = 0;
        return ans;
        
    }
};
