class Solution {
    private:
    int n;
public:
    int findMin(vector<int>& a) {
        
        n = a.size();
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] < a[hi]) hi = mid;
            else if (a[mid] > a[hi]) lo = mid + 1;
            else
                hi--;
        }
        return a[lo];
    }
};
