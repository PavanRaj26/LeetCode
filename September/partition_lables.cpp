class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int n = S.size();
        if (n == 0) return ans;
        int endIndex[26]={0};
        for (int i =0; i < n; i++) {
            endIndex[S[i]-'a'] = i;
        }
        int start = 0;
        int curMax = endIndex[S[0]-'a'];
        int end = 0;
        while(end < n) {            
           
           curMax = max(curMax,endIndex[S[end]-'a']);                        
           if (curMax == end) {
               ans.push_back(end-start+1);
               start = end+1;                                                 
            }            
           end++;
        }
        
        return ans;
    }
};
