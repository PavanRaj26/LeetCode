class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<int> a[27];
        int len = s.size();
        for (int i = 0; i < len; i++) {
            a[s[i]-'a'].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            bool isWord = true;
            int cur = -1;
            int idx[27];
            for (int ii = 0; ii <= 26; ii++) idx[ii] = 0;
            for (int j = 0; j < s.size(); j++) {                
                int jj = s[j] - 'a';
                if (a[jj].size() == 0) {
                    isWord = false;
                    break;
                }
                while (idx[jj] < a[jj].size() && a[jj][idx[jj]] < cur) {
                    idx[jj]++;                    
                }
                if (idx[jj] == a[jj].size()) {
                    isWord = false;
                    break;
                }
                cur = a[jj][idx[jj]++];
            }
            if (isWord) {
                ans++;
            }
        }
        return ans;
    }
};
