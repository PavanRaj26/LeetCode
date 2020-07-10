class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0;
        for (int i = 0; i < 32; i++) {
            int f1 = 0,f2 = 0;
            if ((x & (1 << i))) f1 = 1;
            if ((y & (1 << i))) f2 = 1;
            if (f1 != f2) {
                diff++;
            }
        }
        return diff;
    }
};
