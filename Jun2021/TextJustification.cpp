class Solution {
public:
    string generateString(int st,int i, vector<string> &words,vector<int> &gaps) {
       string res_ = "";
        int gaps_size = gaps.size();
        for (int ii = st; ii <= i; ii++) {
            res_ = res_ + words[ii];
            if (ii - st < gaps_size) {
                string app = "";
                while (gaps[ii-st]--) app = app + " ";
                res_ = res_ + app;
            }
        }
        return res_;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> ans;
        int N = words.size();
        int i = 0;
        int len = 0;
        int st = 0;
        vector<int> gaps;
        len = words[0].size();
        while (i < N) {
            
            
            if (i + 1 < N && len + 1 + words[i+1].size() > maxWidth) {
                int rem_char = maxWidth - len;
                int div = 0;
                int rem = 0;
                int gaps_size = gaps.size();
                //Calculate how much add to gaps
                if (gaps_size != 0) {
                    div = rem_char / gaps_size;
                    rem = rem_char % gaps_size;
                }
                
                for (int j = 0;j < gaps_size; j++) {
                   gaps[j] += div;
                   if (j < rem) {
                       gaps[j] += 1;
                   }
                }
                if (gaps_size == 0) {
                    gaps.push_back(rem_char);
                    gaps_size = 1;
                }
                string res_ = generateString(st,i,words,gaps);
                ans.push_back(res_);
                gaps.clear();
                i++;
                len = words[i].size();
                st = i;
            } else if (i == N - 1)  {
            
                int diff = maxWidth - len; 
                string res_ = generateString(st,i,words,gaps);
                i++;
                
                string app = "";
                while (diff--) app = app + " ";
                res_ = res_ + app;
                ans.push_back(res_);
            } else if (i < N) {
                cout << i << endl;
                i++;
                gaps.push_back(1);                
                len = len + 1 + words[i].size();
                
            }
        }
        return ans;
    }
};