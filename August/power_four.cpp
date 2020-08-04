class Solution {
public:
    bool isPowerOfFour(long long num) {
        if (num == 1) return true;
        long long val = 4;
        while(val < num) {
            val = val * 4;            
        }
        if(val == num) return true;
        return false;
    }
};
