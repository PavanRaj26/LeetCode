class Solution {
public:
    char findTheDifference(string s, string t) {
        int fre1[26]={0};
        for (int i =0; i < t.size(); i++) {
            fre1[t[i]-'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            fre1[s[i]-'a']--;
        }
        for (int i =0; i<26; i++) {
            if (fre1[i] > 0) {
                return i + 'a';
            }
        }
        return 'a';
    }
};
