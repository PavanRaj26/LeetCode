class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int mx = a[n-1];
        vector<int> mxA(n+1,0);
        mxA[n] = 0;
        mxA[n-1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            mxA[i] = max(mxA[i+1],mx - a[i]);
            mx = max(mx,a[i]);
        }
        vector<int> mnA(n,0);
        int mn = a[0];
        int ans = 0;a
        for (int i = 1; i < n; i++) {
            mnA[i] = max(mnA[i-1],a[i] - mn);
            mn = min(mn,a[i]);
            ans = max(ans,mnA[i] + mxA[i+1]);
        }
        return ans;
    }
};
