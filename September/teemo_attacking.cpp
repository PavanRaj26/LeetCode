class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        if (timeSeries.size() == 0) {
            return 0;
        }
        int st = timeSeries[0];
        int end = st + duration - 1;
        
        for (int i =1; i < timeSeries.size(); i++) {
            int cur = timeSeries[i];
            if (end < cur) {
                ans = ans + end - st + 1;
                st = cur;
                end = st + duration - 1;
            } else{
                end = cur + duration - 1;
            }
        }
        ans = ans + (end >= st?end-st+1:0);
        return ans;
    }
};
