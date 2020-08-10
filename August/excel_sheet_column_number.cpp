class Solution {
public:
    int titleToNumber(string s) {
        long long  result = 0;
        for (int i =0;i < s.size(); i++) {
            result = result *1ll* 26;
            result = result + 1ll * (s[i] - 'A' + 1);
        }
        return result;
    }
};
