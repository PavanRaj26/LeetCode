class Solution {
    private:
    set<long long> S;
    public:
    int nthUglyNumber(int n) {
        int cnt = 1;
        S.insert(1ll);
        for (int i = 1; i <= n; i++) {
            set<long long>::iterator it = S.begin();
            long long num = (*it);
            S.erase(it);
            if (cnt == n) return num;
            S.insert(num*2);
            S.insert(num*3);
            S.insert(num*5);
            cnt++;
        }
        return 1;
    }
};
