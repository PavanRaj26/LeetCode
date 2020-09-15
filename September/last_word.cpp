class Solution {
public:
    int lengthOfLastWord(string s) {
     int n = s.size();
     reverse(s.begin(),s.end());
        string ans = "";
        int cnt = 0;
     for (int i =0; i < n; i++) {
         if (s[i] != ' ') {
             string t(1,s[i]);
             ans = ans + t;
         } else if (s[i]==' ') {
             if (ans.size() > 0) {
                 return ans.size();
             }
         }
     }
        
        return ans.size();
    }
};
