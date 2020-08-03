class Solution {
public:
    bool notAlpha(char c) {
        if (c >= 'a' && c<='z') return false;
        if (c >= 'A' && c <= 'Z') return false;
        if (c >= '0' && c <= '9') return false;
        return true;
    }
    char lower(char c) {
        if (c >= 'A' && c <= 'Z') return c + 32;
        if (c >= 'a' && c <= 'z') return c;
        return c;
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        int n = s.size();
        while (l < r) {
            while(l < r && notAlpha(s[l])) {
                l++;
            }
            while(l < r && notAlpha(s[r])) {
                r--;
            }
            if (lower(s[l]) != lower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
