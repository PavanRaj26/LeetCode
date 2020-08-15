class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector< pair<int,int> > v;
        int n = intervals.size();
        if (n == 0) {
            return 0;
        }
        for (int i =0; i< n; i++) {
            v.push_back(make_pair(intervals[i][1],intervals[i][0]));            
        }
        sort(v.begin(),v.end());
        int end = v[0].first;
        int ans = 0;
        for (int i =1; i < n; i++) {
            int start = v[i].second;
            if (start < end) {
                ans++;
            }
            else {
                end = v[i].first;
            }
        }        
        return ans;
    }
};
