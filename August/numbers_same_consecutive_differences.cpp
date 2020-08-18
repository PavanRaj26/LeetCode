class Solution {
    vector<int> ans;
    
public:
    void recur(int idx,int res,int no,int K,int n) {
        if (idx == n) {
            ans.push_back(res);
            return ;
        }
        if (no + K >= 0 && no + K <= 9) {
            int res1 = res * 10 + no + K;
            recur(idx+1,res1,no+K,K,n);            
        }
        if (K != 0 && no - K >= 0 && no - K <= 9) {
            int res1 = res * 10 + no - K;
            recur(idx+1,res1,no-K,K,n);            
        }            
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        
        if (N == 1) {
            ans.push_back(0);            
        }
        for (int i = 1;i <= 9; i++) {
            recur(1,i,i,K,N);
            
        }
        return ans;
    }
};
