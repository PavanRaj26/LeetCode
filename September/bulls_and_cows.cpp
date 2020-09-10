class Solution {
    private:
        set<int> s[10];
public:
    string getString(int no) {
        if (no == 0) {
            return "0";
        }
        string res = "";
        while(no) {
            string t(1,no%10 + '0');
            res = res + t;
            no /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }    
    string getHint(string secret, string guess) {
        int n2 = guess.size();
           for (int i = 0; i < n2; i++) {
               s[guess[i]-'0'].insert(i);
           }
        int cnt0 = 0;
        int cnt1 = 0;
        vector<int> mark(n2,0);
        for (int i = 0; i < secret.size(); i++) {
            int no = secret[i]-'0';
            if (s[no].find(i) != s[no].end()) {
                cnt0++;
                s[no].erase(i);
                mark[i] = 1;
            }            
        }
        for (int i = 0; i < secret.size(); i++) {
            int no = secret[i] - '0';
            if(mark[i]) continue;
            if (s[no].size() > 0) {
                cnt1++;                                
                set<int>::iterator it = s[no].begin();
                s[no].erase(it);
            }
        }
        
        string res = getString(cnt0) + "A" + getString(cnt1) + "B";
        return res;
    }
};
