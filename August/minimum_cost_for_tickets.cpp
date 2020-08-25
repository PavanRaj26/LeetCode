class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        sort(days.begin(),days.end());
        int nSize =  days[n-1];
        vector<bool> travelDay(nSize+3,0);
        vector<int> dp(nSize+3,0);
        for (int i = 0; i < n; i++) {
            travelDay[days[i]] = true;
        }
        for (int i =1; i <= nSize; i++) {
            if (travelDay[i]) {
                int one = dp[max(i-1,0)] + costs[0];
                int seven = dp[max(i-7,0)] + costs[1];
                int mon = dp[max(i-30,0)]  + costs[2];
                dp[i] = min(one,seven);
                dp[i] = min(dp[i],mon);
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[nSize];
    }
};
