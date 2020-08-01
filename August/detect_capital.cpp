class Solution {
public:
    bool detectCapitalUse(string word) {
        int f = 1;
        int cntL = 0;
        int cntU = 0;
        if (word.size() == 0) return true;
        for (int i =0; i <word.size(); i++) {
            if (word[i] >= 'a' && word[i] <='z') cntL++;
            else cntU++;
        }
        if (cntL == word.size() || cntU == word.size()) return true;
        if (word[0] >= 'a' && word[0] <= 'z' || cntU >= 2) {
            return false;
        }
        return true;
    }
};
