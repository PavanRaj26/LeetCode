#include<bits/stdc++.h>
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int,int> > v(n);
        
        for (int i = 0; i < n; i++) {
                v[i].first = boxTypes[i][1];
                v[i].second = boxTypes[i][0];
        }       
        sort(v.begin(),v.end(),greater<pair<int,int> >());
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cnt + v[i].second > truckSize) {
                ans = ans + v[i].first * (truckSize - cnt);
                break;
            } else {
                ans = ans + v[i].second * v[i].first; 
                cnt = cnt + v[i].second;    
            }
        }
        return ans;
    }
};