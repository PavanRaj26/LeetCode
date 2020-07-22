class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        
        int n= a.size();
        vector<int> ans;
        int xor_ = a[0];
        for (int i =1 ; i < n; i++) {
            xor_ = xor_ ^ a[i];
        }
        int sBit = xor_ & ~(xor_ - 1);
        int x= 0;
        int y = 0;
        for (int i = 0; i < n; i++) {
            if (sBit & a[i]) {
                x = x ^ a[i];
            }
            else {
                y = y ^ a[i];
            }
        }
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};
