class Solution {
    
public:
    
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<int> adj[n];
        vector<int> ans;
        if (n == 0) return ans;
        int sz = v.size();
        int in_degree[n];
        for (int i = 0; i < n; i++) in_degree[i] = 0;
        for (int i= 0; i < sz; i++) {
            adj[v[i][1]].push_back(v[i][0]);
            
        }
        for (int i = 0; i <n; i++) {
            vector<int>::iterator it = adj[i].begin();
            for (; it!= adj[i].end(); it++) {
                int x= (*it);
                in_degree[x]++;
            }
        }
        queue<int> Q;
        
        for (int i = 0 ;i < n; i++) {
            if (in_degree[i] == 0) Q.push(i);
        }
        int cnt= 0;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            ans.push_back(u);
            
            vector<int>::iterator it = adj[u].begin();
            for (;it!=adj[u].end();it++) {
                int x = (*it);
                if (--in_degree[x] == 0) {
                    Q.push(x);
                }
            }
            cnt++;
        }
        if (cnt != n) 
            return vector<int>(0);
        return ans;
    }
};
