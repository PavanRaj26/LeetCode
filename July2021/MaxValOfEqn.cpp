class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& a, int k) {
        int ans = -200000004;
        int n = a.size();
        int rIdx = 1;
        int lIdx = 0;
        deque<int> dq;
        while (lIdx < n) {
                
            while (rIdx < n && a[rIdx][0] - a[lIdx][0] <= k) {
                
                while (!dq.empty() && a[dq.back()][1] + a[dq.back()][0] < a[rIdx][1] + a[rIdx][0]) 
                    dq.pop_back();
                dq.push_back(rIdx);
                rIdx++;
            }
            while (!dq.empty() && dq.front() <= lIdx) {
                dq.pop_front();
            }
            if (!dq.empty()) {
                ans = max(ans,a[dq.front()][0] - a[lIdx][0] + a[dq.front()][1] + a[lIdx][1]);
            }
            lIdx++;
        }
        return ans;
    }
};