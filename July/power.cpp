class Solution {
public:
    double power(double x, long long y) 
{ 
    double res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}
    double myPow(double x, long long n) {
        int sn = 1;
        int sn1 = 1;
        if (x == 1) return 1;
        if (x == -1) {
            if (n % 2 == 0) return 1;
            if (n % 2 != 0) return -1;
        }
        if (x < 0 && n % 2 != 0) {
            sn = -1;
            x = -x;
        }
        if (n < 0){ 
            n = -n;
            sn1 = -1;
        }
        double ans = power(x,n);
        if (sn1 == -1) 
            ans = 1 / ans;
        return sn * ans;
    }
};
