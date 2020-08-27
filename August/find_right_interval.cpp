class Solution {
    private:
    struct E {
        int st;
        int end;
        int idx;        
    };
public:
    
    vector<int> findRightInterval(vector<vector<int>>& A) {
        int n = A.size();
        vector< E> v;
        for(int i =0; i < n; i++) {
            E e;
            e.st = A[i][0];
            e.end = A[i][1];
            e.idx = i;
            v.push_back(e);
        }
        sort(v.begin(),v.end(),[](const E &lhs,const E &rhs) {
            if (lhs.st < rhs.st) {
                return true;
            }
            else if (lhs.st > rhs.st) {
                return false;
            }
            else {
                return lhs.idx < rhs.idx;
            }
        });        
        vector<int> ans(n,0);
        for (int i =0; i < n; i++) {
            int key = v[i].end;
            int lo = i+1;
            int hi = n;
            while(lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (v[mid].st >= key) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            if (lo >= n || v[lo].st < key) ans[v[i].idx] = -1;
            else ans[v[i].idx] = v[lo].idx;            
        }
        return ans;
    }
};
