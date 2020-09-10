class Solution {
public:
    int getNo(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1 && s[0] == '0') {
            return 0;
        }
        int no = 0;
        int i =0;
        int n = s.size();
        while(i < n && s[i] == '0') {
            i++;            
        }
        while(i < n) {
            no = no * 10 + s[i] - '0';
            i++;
        }
        return no;
    }
    int compareVersion(string s1, string s2) {
        int i = 0;
        int j = 0;
        int n = s1.size();
        int m = s2.size();
        while(i < n || j < m) {
            string res1 = "";
            string res2 = "";
            while(i < n && s1[i] != '.') {                
                string t(1,s1[i]);
                res1 = res1 + t;
                i++;
            }
            i++;
            while(j < m && s2[j] != '.') {
                
                string t(1,s2[j]);
                res2 = res2 + t;
                j++;
            }
            j++;
            int n1 = getNo(res1);
            int n2 = getNo(res2);
            if (n1 == n2) continue;
            if (n1 > n2) return 1;
            if (n1 < n2) return -1;
        }
    return 0;
        
    }
};
