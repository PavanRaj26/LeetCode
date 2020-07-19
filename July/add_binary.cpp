class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int aSz = a.size();
        int bSz = b.size();
        string res = "";
        int car = 0;
        int i = 0;
        while(1) {
            if (i >= aSz && i >= bSz) break;
            int a1 = (i < aSz && a[i] == '1'?1:0);
            int b1 = (i < bSz && b[i] == '1'?1:0);
            int sum = (a1 + b1 + car) % 2;
            car = (a1 + b1 + car) / 2;
            string t(1,sum+'0');
            res = res + t;
            i++;
        }
        if (car == 1) {
            string t(1,'1');
            res = res + '1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
