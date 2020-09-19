class Solution {
    vector<int> ans;
    int a;
    int b;
public:
    
    int getNo(vector<int > v) {
        int sz = v.size();
        if (sz > 9) return -1;
        int res = 0;
        if (sz == 0) {
        return 0;
        }
        for (int i =0; i < sz; i++) {
            res = res *10 + v[i]; 
        }
        return res;
    }
    void recur(vector<int> v) {
        int no = getNo(v);
        if (no > b || no == -1) {
            return ;
        }
        if (no >= a && no <= b) {
            ans.push_back(no);    
        }    
        if (v.size() == 0) {
            for (int i=1; i <=9; i++) {
                v.push_back(i);
                recur(v);
                v.pop_back();
            }
        } else {
            if (v[v.size()-1] < 9) {
                v.push_back(v[v.size()-1]+1);
                recur(v);
                v.pop_back();
            }
        }
        
    }
    vector<int> sequentialDigits(int low, int high) {
        a = low;
        b = high;
        vector<int> v;
        recur(v);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
