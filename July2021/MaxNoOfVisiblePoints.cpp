class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        
        vector<double> pa;
        int st = 0;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            if (x == location[0] && y == location[1]) {
                st++;
            } else {
                double ang = atan2(y - location[1], x - location[0]) * 180.0 / M_PI;
                if (ang < 0) ang += 360;
                pa.push_back(ang);
            }
        }
        sort(pa.begin(),pa.end());
        int n = pa.size();
        int l = 0;
        int ans = 0;
        for(int i=0; i<n; i++)
            pa.push_back(pa[i] + 360);
        for (int rt = 0; rt < pa.size(); rt++) {
            
            while ((pa[rt] - pa[l]) > angle) {
                l++;
            }
            ans = max(ans,rt - l + 1);
        }
        return ans + st;
    }
};