class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int K) {
        
        int st = 0;
        int cnt = 0;
        int n = a.size();
        
        if (K == 0 || n == 0) {        
            return 0;
        }
        long long res = a[0];
        for (int end = 1; end <= n; end++) {
            
            while(res >= K && st < end) {
                res = res / a[st];
                st++;                
            }
            int len = end - st;
            cnt = cnt + len;                                                      
            if (end < n) {
                res = res * a[end];
            }
        }
        return cnt;
    }
};
