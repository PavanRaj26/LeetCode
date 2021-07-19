class Solution {
public:
    int myAtoi(string s) {
        long long int res = 0;
        int mn = INT_MIN;
        int mx = INT_MAX;
        int n = s.size();
        bool pos = true;
        bool neg = false;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cnt >= 2) return 0;
            if(s[i] >= '0' && s[i] <= '9') {
                int len = 0;
                while (i < n && (s[i] >= '0' && s[i] <= '9')) {
                    res = res * 10 + (s[i] - '0');
                    i++;
                    
                    len++;
                    if (len >= 11 && res >= mx) break;
                }
                if (neg) {
                    if (-res < mn * 1ll) {
                        return mn;
                    }
                    return -res;
                }  
                if (pos) {
                    if (res > mx * 1ll) {
                        return mx;
                    }
                    return res;   
                }
            } else if (s[i] == '-') {
                neg = true;
                if (cnt) return 0;
                cnt++;
            } else if (s[i] == '+') {
                pos = true;
                if (cnt) return 0;
                cnt++;
            } else if (s[i] != ' ') {
                return 0;
            } else if (s[i] == ' ') {
                if (cnt) return 0;
            }
        }
        return res;
    }
};