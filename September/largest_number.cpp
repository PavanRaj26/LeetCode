class Solution {
public:
    static bool cmp(const string X,const string Y) {
        string XY = X + Y;
        string YX = Y + X;
        int val = XY.compare(YX);
        if (val < 0) {
            return 0;
        } else {
            return 1;
        }                
    }
    string getStr(int no) {
        string res = "";
        if (no == 0) {
            return "0";
        }
        while(no) {
            string t(1,no%10+'0');
            res = res + t;
            no = no / 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        int f = 1;
        for (int i =0; i< nums.size(); i++) {
            int no = nums[i];
            if (no != 0) f = 0;
            string s= getStr(no);
            v.push_back(s);
        }
        if (f) {
            return "0";
        }
        sort(v.begin(),v.end(),cmp);
        string res ="";
        for (int i =0; i < v.size(); i++) {                        
            res = res + v[i];
        }
        
        return res;
    }
};
