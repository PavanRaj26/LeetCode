class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n = a.size();
        vector<int> ans;
        vector<pair<int,int> > v;
        if (k > n) return ans; 
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
       unordered_map<int,int>::iterator it = mp.begin();
        for (; it!= mp.end(); it++) {
            v.push_back(make_pair((*it).second,(*it).first));
        }
        sort(v.begin(),v.end(),greater<pair<int,int> >());
            
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
