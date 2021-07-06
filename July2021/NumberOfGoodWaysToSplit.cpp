class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        int h1[27] = {0};
        int h2[27] = {0};
        int d1 = 0;
        int d2 = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            h2[s[i]-'a']++;
            if (h2[s[i]-'a'] == 1) d2++;
        }
        for (int i = 0;i < n; i++) {
            int val = s[i] - 'a';
            h2[val]--;
            if (h2[val] == 0) d2--;
            h1[val]++;
            if (h1[val] == 1) d1++;
            if (d1 == d2) {
                ans++;
            }
        }
        return ans;
    }
};