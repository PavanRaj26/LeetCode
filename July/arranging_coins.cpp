class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 1) return 1;
        for (long long i = 1; i <= n; i++) {
            if (i * 1ll * (i + 1) > 2 *1ll* n) {
                return i - 1;
            }
        }
        return 0;
    }
};
