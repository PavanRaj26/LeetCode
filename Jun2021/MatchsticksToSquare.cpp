class Solution {
    private:
    long long s1[4]={0};
    int cnt[4] = {0};
    public:
    bool recur(int len, vector<int>& a,int sum) {
        if (len == a.size()) { 
            for (int i = 0;i < 4; i++) {
                if (cnt[i] == 0 || (i && s1[i] != s1[i-1])) {
                    return false;
                }
            }
            return true;
        }
        for (int i = 0; i < 4; i++) {
            if (s1[i] + a[len] > sum) {
                continue;
            }
            s1[i] = s1[i] + a[len];
            cnt[i]++;
            if (recur(len+1,a,sum)) {
                return true;
            }
            s1[i] = s1[i] - a[len];
            cnt[i]--;            
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n <= 3) {
            return false;
        } 
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + matchsticks[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        return recur(0,matchsticks,sum/4);
    }
};