class Solution {
    private:
    vector<vector<int> > ans;
    int tar;
    bool vis[15];
public:
    void dfs(int i,vector<vector<int>>& graph,vector<int> &tmp) {

        if (i == tar) {
            ans.push_back(tmp);
            return;
        }
        if (vis[i] == false) {
            vis[i] = true;
            for (int j = 0;j <graph[i].size(); j++) {
                int x = graph[i][j];
                tmp.push_back(x);
                dfs(x,graph,tmp);
                tmp.pop_back();
            }
            vis[i] = false;
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if (graph.size() == 0) return ans;
        tar = graph.size() - 1;
        vector<int> tmp;
        tmp.push_back(0);
        dfs(0,graph,tmp);
        return ans;
    }
};
