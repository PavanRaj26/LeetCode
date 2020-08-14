class Solution {
    private:
    map<char,int> mp;
public:
    
    int longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return 0;
        for (int i =0; i < n; i++) {
            mp[s[i]]++;
        }        
        map<char,int>::iterator it = mp.begin();
        int ans = 0;
        int mx = 0;
        vector<int> odd;
        int f = 0;
        for (; it!= mp.end();it++) {
            int cnt = (*it).second;
            if (cnt %2!= 0) {
                f = 1;
                ans = ans + cnt - 1;
            }
            else {
                ans += cnt;
            }
        }
        if (f == 1) ans = ans + 1;
        return ans;
    }
};
