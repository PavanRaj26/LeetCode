class Solution {
public:
    vector<string> generateParenthesis(int n) {
     
        vector<string> ans;
        
        for (int i = 0; i < (1<< (2 * n)) ; i++) {
            stack<int> st;
            int bal = 1;
            for (int k = 0; k < 2 * n; k++) {
                if (i & (1 << k)) {
                    st.push(k);
                } else {
                    if (st.size() == 0) {
                        bal = 0;
                        break;
                    } else {
                        st.pop();
                    }
                }
            }
            if (st.size() > 0) {
                bal = 0;
            }
            if (bal) {
                string res="";
                for (int k = 0; k < 2 * n; k++) {
                    if (i & (1 << k)) {
                        string c(1,'(');
                        res += c;
                    } else {
                        string c(1,')');
                        res += c;
                    }
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};
