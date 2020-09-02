class Solution {public:    bool containsNearbyAlmostDuplicate(vecto     r<int>& A, int k, int t) {        vector<pair<long long,int> > v;                int n = A.size();        for (int i = 0; i < n; i++) {                   v.push_back(make_pair(A[i],i));         }        sort(v.begin(),v.end       ());        for (int i =0 ; i < n; i++) {            int j = i + 1;                        while (j < n && v[j].first - v[i].first <= (long long) t) {                  if (v[j].second - v[i].second <= k && v[j].second- v[i].second >= -k) {                    return true;                 }                          j++;            }         }                  return false;               }       };class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
        vector<pair<long long,int> > v;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            v.push_back(make_pair(A[i],i));
        }
        sort(v.begin(),v.end());
        for (int i =0 ; i < n; i++) {
            int j = i + 1;
            while (j < n && v[j].first - v[i].first <= (long long) t) {
                if (v[j].second - v[i].second <= k && v[j].second- v[i].second >= -k) {
                    return true;
                }
                j++;
            }
        }        
        return false;
    }
    
};
