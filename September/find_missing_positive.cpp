class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int fre[100005]={0};        
        for (int i =0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                int temp =nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }                        
        }
        for (int i =0; i < j; i++) {
            
            int no = nums[i]; 
            if (abs(no) <= j && fre[abs(no)-1] == 0) {
            nums[abs(no)-1] = -nums[abs(no)-1];            
                fre[abs(no)-1] = 1;
            }
            // cout << no <<" ";

        }
        // cout << j << endl;
        for (int i = 0; i < j; i++) {
            
            if (nums[i] > 0) {
                return i + 1;                
            }
        }        
        return j+1;
    }
};
