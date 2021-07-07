class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
         vector< pair<int,double> > a;
        int n = cars.size();
        stack<int> st;
        vector<double> ans(n,-1);
        st.push(n-1);
        for (int i = n - 2; i >= 0; i--) {
            
            while(!st.empty() && cars[i][1] <= cars[st.top()][1]) {
                st.pop();
            }
            while(!st.empty()) {
                double time_to_collide=(cars[st.top()][0]-cars[i][0])*1.0/(cars[i][1]-cars[st.top()][1]); 
                if (time_to_collide < ans[st.top()] || ans[st.top()] < 0) {
                    ans[i] = time_to_collide;
                    break;
                }    
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};