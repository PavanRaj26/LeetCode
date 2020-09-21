class Solution {
public:
    static bool comp(const pair<int,int> &a, const pair<int,int> &b) {
        if (a.first < b.first) {
            return 1;
        } else if (a.first > b.first) {
            return 0;
        }
        return a.second < b.second;        
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
             
        vector<pair<int,int> > v;
        int n = trips.size();
        if (n == 0) {
            return true;
        }
        for (int i =0; i < n; i++) {                        
            v.push_back(make_pair(trips[i][1],+trips[i][0]));
            v.push_back(make_pair(trips[i][2],-trips[i][0]));
        }        
        sort(v.begin(),v.end(),comp);
        int mx = 0;
        for (int i = 0; i < v.size(); i++) {
            mx = mx + v[i].second;
            if (mx > capacity) {
                return false;
            }
        }
        return true;
    }
};
