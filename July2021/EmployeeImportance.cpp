/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    vector<int > adj[2002];
    bool vis[2002];    
    int imp[2002];
    int dfs(int i) {        
        int sum = imp[i];
        for (int j = 0;j < adj[i].size(); j++) {
            sum = sum + dfs(adj[i][j]);
        }
        return sum;
    }
public:
    int getImportance(vector<Employee*> a, int id) {
       int n = a.size();
       for (int i = 0; i < 2002; i++) vis[i] = false;
       for (int i = 0; i < n; i++) {
           int x = a[i]->id;
           imp[x] = a[i]->importance;
           for (int j = 0; j < a[i]->subordinates.size(); j++) {
               adj[x].push_back(a[i]->subordinates[j]);
           }
       }
       return dfs(id);
    }
};