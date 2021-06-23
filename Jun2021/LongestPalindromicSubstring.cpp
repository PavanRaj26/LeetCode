class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int len = 1;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            int len_1 = 1;
            int ii = i;
            int lo = ii - 1;
            int hi = ii + 1;
            while (lo >= 0 && hi < n && s[lo] == s[hi]) {
                len_1 += 2;
                lo--;
                hi++;
            }
            if (len_1 > len) {
                len = len_1;
                idx = lo + 1;
            }
            lo = ii;
            hi = ii+1;
            len_1 = 0;
            while (lo >= 0 && hi < n && s[lo] == s[hi]) {
                len_1 += 2;
                lo--;
                hi++;
            }
            if (len_1 > len) {
                len = len_1;
                idx = lo + 1;
                
            }
        }
        return s.substr(idx,len);
    }
};