class Solution {
public:
    int maxScore(vector<int>& a, int k) {
       
        int n = a.size();
        int ans = 0;
        int curSum = 0;
        
        for (int i = 0; i < n - k; i++) {
            curSum += a[i];
        }
        int mnSum = curSum;
        int totSum = curSum;
        for (int i = n - k; i < n; i++) {
            curSum = curSum - a[i + k - n];
            curSum = curSum + a[i];
            mnSum = min(mnSum, curSum);
            totSum = totSum + a[i];
        }
        return totSum - mnSum;
    }
};
