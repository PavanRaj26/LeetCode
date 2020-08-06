class Solution {
    
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> a;
        int n= nums.size();
        a.push_back(0);
        vector<int> ans;
        for (int i = 0; i <n ; i++) a.push_back(nums[i]);
        for (int i =1 ; i <= n; i++) {
            if (a[abs(a[i])] >= 0) {
                a[abs(a[i])] = -a[abs(a[i])];
            }
            else {
                ans.push_back(abs(a[i]));
            }
        }  
        return ans;
    }
};
