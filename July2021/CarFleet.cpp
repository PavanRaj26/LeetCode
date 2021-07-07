class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector< pair<int,double> > a;
        int n = position.size();
        if (n == 0) return 0;
        for (int i = 0; i < n; i++) {
            pair<int,double> pii;
            a.push_back(make_pair(position[i],(target - position[i]) * 1.0 / speed[i]));            
        }
        sort(a.begin(),a.end());
        int ans = 1;
        double mx = a[n - 1].second;
        for (int i = n - 1; i >= 0; i--) {
           double d1 = a[i].second;
           if (d1 - mx > 0.000001) {
               ans++;
               mx = d1;
           }
        }
        return ans;
    }
};