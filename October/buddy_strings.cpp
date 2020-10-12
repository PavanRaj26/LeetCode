class Solution {
public:
    bool buddyStrings(string A, string B) {
        int s = A.size();
        if (s != (int)B.size()) {
            return false;
        }
        int diff = 0;
        int idx1 = -1;
        int idx2 = -1;
        int hs[27] ={0};
        for (int i =0; i < s; i++) {
            if (A[i] != B[i]) {
                diff++;
                if (idx1 == -1) {
                    idx1 = i;
                    idx2 = i;
                } else {
                    idx2 = i;
                }
            }
            hs[A[i]-'a']++;
        }        
        if (diff > 2) {
            return false;
        }
        if (idx1 == -1) {
            for (int i =0; i < 26; i++) {
                if (hs[i] > 1) {
                    return true;
                }
            }        
            return false;
        }
        if (A[idx1] != B[idx2] || A[idx2] != B[idx1]) {
            return false;
        }
        return true;
    }
};
