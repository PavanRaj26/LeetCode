class Solution {
    private:
    unordered_map<int,int> mp;
    unordered_map<int,int> mp1;
    unordered_map< int,unordered_map<int,int > > mp2;
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int> > ans;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        if (mp.find(0) != mp.end() && mp[0] >= 3) {
            vector<int> tmp(3,0);
            ans.push_back(tmp);
        }
        if (mp.find(0) != mp.end()) {
            for (int i = 0; i < n; i++) {
                if (a[i] > 0) {
                    if (mp1.find(a[i]) == mp1.end() && mp.find(-a[i]) != mp.end()) {
                        mp1[a[i]] = 1;
                        vector<int> tmp;
                        tmp.push_back(0);
                        tmp.push_back(a[i]);
                        tmp.push_back(-a[i]);
                        ans.push_back(tmp);
                    }
                }
            }
        }
        mp1.clear();
        for (int i = 0; i < n; i++) {
            
            if (a[i] != 0 && mp[a[i]] >= 2 && mp1.find(a[i]) == mp1.end()) {
                
                if (mp.find(-2*a[i]) != mp.end()) {
                    vector<int> tmp;
                    mp1[a[i]] = 1;
                    tmp.push_back(a[i]);
                    tmp.push_back(a[i]);
                    tmp.push_back(-2*a[i]);
                    ans.push_back(tmp);
                }
            }   
        }
        mp1.clear();
        for (int i = 0; i < n; i++) {
            if (mp1.find(a[i]) != mp1.end()) continue;
            for (int j = i + 1;j < n; j++) {
                if (abs(a[i]) != abs(a[j]) && a[i] != 0 && a[j] != 0) {
                    if (-a[i]-a[j] == a[i] || -a[j]-a[i] == a[j]) continue;
                    if (mp2.find(a[i]) != mp2.end() && mp2[a[i]].find(a[j]) != mp2[a[i]].end()) {
                        continue;
                    }
                    if (mp.find(-a[i]-a[j]) != mp.end()) 
                    
                    {
                        
                        mp2[a[i]][a[j]]=1;
                        mp2[a[j]][a[i]]=1;
                        mp2[a[i]][-a[i]-a[j]]=1;
                        mp2[a[j]][-a[j]-a[i]]=1;
                        mp2[-a[j]-a[i]][a[i]]=1;
                        mp2[-a[j]-a[i]][a[j]]=1;
                        
                        vector<int> tmp;
                        tmp.push_back(a[i]);
                        tmp.push_back(a[j]);
                        tmp.push_back(-a[i]-a[j]);
                        ans.push_back(tmp);
                    }
                }
            }
            mp1[a[i]] = 1;
        }
        return ans;
    }
};
