#define ll long long
class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        ll tmpCandies= candies;
        vector<int> a(n,0);
        for (int i =0; i < n;i++) a[i] = 0;
        ll base = 0;
        int f = 0;
        while (candies > 0) {
            for (int i = 0; i < n;i++) {
              if (base + i + 1 <= candies) {
                  a[i] = a[i] + base + i + 1;
                  candies = candies - base - i - 1;
              }else {
                  a[i] = a[i] + candies;
                  candies =0;
                  break;
              }                                
            }       
            base = base + n;
        }
        return a;
    }
};
