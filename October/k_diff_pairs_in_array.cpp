class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int ans = 0;
        set<int> S;
        map<int,int> mp;
        for (int i =0; i < nums.size(); i++) {            
            mp[nums[i]]++;
            S.insert(nums[i]);            
        }
        if (k == 0) {
            map<int,int>::iterator it = mp.begin();
            for (; it!=mp.end();it++) {
                if ((*it).second > 1)  {
                    ans = ans + 1;
                }
            }
            return ans;
        }
        set<int>::iterator it = S.begin();
        for (;it!=S.end();it++) {
           int x = (*it);
           int tar = x + k;
           // multiset<int>::iterator its = S.lower_bound(tar);
           // int dist = distance(it,its);
           // multiset<int>::iterator itf = S.lower_bound(x);
           // int dist1 = distance(itf,it);            
           set<int>::iterator its = S.upper_bound(tar);
           its--;
           cout <<x <<" "<<tar<<" "<<ans<<" "<<(*its)<<endl;
           if (*its == tar) {
               ans = ans + 1;
           }                           
        }
        return ans;
    }
};
