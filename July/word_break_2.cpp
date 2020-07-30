class Solution {
    private:
    unordered_map<string,  
            vector<string> > mp; 
  
// Unordered_set used  
// to store the dictionary. 
unordered_set<string> dict; 
  
public:
    
    vector<string> combine( 
     vector<string> prev, string word){ 
      
    // Loop to find the append string 
    // which can be broken into 
    for (int i = 0; i < prev.size(); i++) { 
        prev[i] += " " + word; 
    } 
    return prev; 
} 
  
// Utility funtion for word Break  
vector<string> wordBreakUtil(string s) 
{    
    // Condition to check if the 
    // subproblem is already computed 
    if (mp.find(s) != mp.end()) 
        return mp[s]; 
    vector<string> res; 
      
    // If the whole word is a dictionary 
    // word then directly append into  
    // the result array for the string 
    if (dict.find(s) != dict.end()) 
        res.push_back(s); 
      
    // Loop to iterate over the substring 
    for (int i = 1; i < s.length(); i++) { 
        string word = s.substr(i); 
          
        // If the substring is present into 
        // the dictionary then recurse for 
        // other substring of the string 
        if (dict.find(word) != dict.end()) { 
            string rem = s.substr(0, i); 
            vector<string> prev =  
             combine(wordBreakUtil(rem), word); 
            res.insert(res.end(),  
                 prev.begin(), prev.end()); 
        } 
    } 
      
    // Store the subproblem  
    // into the map 
    mp[s] = res; 
    return res; 
} 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
//         Node * head = newNode();
//         int n = s.size();
     
//                 vector<string> ans;
//         if (wordDict.size() == 0 || n == 0) return ans;
//         for (int i =0; i < wordDict.size(); i++) {
//             string t = wordDict[i];
//             Node *ptr = head;
//             for (int j =t.size()-1 ; j >=0; j--) {
//                int no = t[j] - 'a';
//                 if (ptr->v[no] == NULL) {
//                     ptr->v[no] = newNode();                    
//                 }
//                 ptr = ptr->v[no];
//             }
//             ptr->isEnd = true;
//             mxLen = max(mxLen,(int)t.size());
//         }
//         vector<string> dp[n];
        
//         for (int i = 0; i < n; i++) {
//             Node *ptr = head;
//             for (int j = 1; j <= mxLen; j++) {
//                 if (i - j + 1 < 0) break;
//                 int no = s[i-j+1]-'a';
                
//                 if (ptr->v[no] == NULL) break;
//                 else {
//                     ptr = ptr->v[no];
//                 }
//                 if (ptr->isEnd) {
//                     if (i - j >= 0) {
//                         for (int k = 0; k < dp[i-j].size(); k++) {
                            
//                            dp[i].push_back(dp[i-j][k]+" "+s.substr(i-j+1,j));     
//                         }
//                     }
//                     else {
//                         dp[i].push_back(s.substr(i-j+1,j));
//                     }
//                 }
//             }
//         }
//         // for (int k =0 ; k < dp[n-1].size(); k++) {
//         //     reverse(dp[n-1][k].begin(),dp[n-1][k].end());
//         //     ans.push_back(dp[n-1][k]);
//         // }
//         return dp[n-1];
        mp.clear(); 
    dict.clear(); 
    dict.insert(wordDict.begin(), wordDict.end()); 
    return wordBreakUtil(s);
    }
    
};
