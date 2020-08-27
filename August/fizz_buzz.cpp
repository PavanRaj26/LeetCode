class Solution {
public:
    
    vector<string> fizzBuzz(int n) {
        string f = "Fizz";
        string b = "Buzz";
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            string r="";
            if (i % 15 ==0) {
                r = r + f + b;
            } else if (i % 5 == 0) {
                r = r + b;
            } else if (i % 3 == 0) {
                r = r + f;
            } else {
                int tmp = i;
                while(tmp) {
                    int a = tmp % 10;
                    tmp /= 10;
                    string tt(1,a+'0');
                    r=r+tt;                
                }
                reverse(r.begin(),r.end());
            }
            ans.push_back(r);
        }
        return ans;
    }
};
