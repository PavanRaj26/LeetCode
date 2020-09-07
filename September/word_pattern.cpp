class Solution {
    private:
    map<char,string> mp;
    map<string,char> mp1;
public:
    bool wordPattern(string pattern, string str) {
        
        int j = 0;
        bool f = true;
        int cnt = 0;
        for (int i =0; i < pattern.size(); i++) {
            char c = pattern[i];
            string res = "";
            if (j >= str.size()) {
                return false;
            }
            while(j < str.size() && str[j] != ' ') {
                string t(1,str[j]);
                res = res + t;
                j++;
            }
            j++;
            if (mp1.find(res) == mp1.end()) {
                mp1[res] = c;
            } else {
                if (mp1[res] != c) {
                    return false;
                }
            }
            if (mp.find(c) == mp.end()) {
                mp[c] = res;
            } else {
                string ress = mp[c];
                if (ress.size() != res.size()) {return false;}
                for (int k = 0; k<res.size(); k++) {
                    if (ress[k] != res[k]) {
                        return false;
                    }
                }
            }            
        }
        if (j < str.size()) {
            return false;
        }
        return true;
    }
};
