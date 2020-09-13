class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];        
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        int n = intervals.size();
        int x = newInterval[0];
        int y = newInterval[1];
        int lt = -1;
        int rt = -1;
        for (int i =0; i < n; i++) {
            int x1 = intervals[i][0];
            int y1 = intervals[i][1];
            if ((x1 < x && y1 < x) || (x1 > y && y1 > y)) {
                vector<int> tmp(2);
                tmp[0] = x1;
                tmp[1] = y1;
                ans.push_back(tmp);                
            }
            else {
                if (lt == -1) {
                    lt = min(x1,x);
                } else {
                    lt = min(lt,x1);
                    lt = min(lt,x);
                }
                if (rt == -1) {
                    rt = max(y1,y);                    
                } else {
                    rt = max(rt,y1);
                    rt = max(rt,y);
                }
            }
        }
        vector<int> tmp(2);
        tmp[0] = lt;
        tmp[1] = rt;
        if (lt == -1 && rt == -1) {
            tmp[0] = x;
            tmp[1] = y;
        }
        ans.push_back(tmp);
        sort(ans.begin(),ans.end(),comp);
        return ans;
    }
};
