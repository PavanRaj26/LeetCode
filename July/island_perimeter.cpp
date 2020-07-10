class Solution {
    
    private:
    int dir1[4] = {-1,0,0,1};
    int dir2[4] = {0,-1,1,0};
    int ans= 0;
public:
    void dfs(int i,int j,vector<vector<int>>& grid) {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 ||
            grid[i][j] == -1) {
            return ;
        }
        grid[i][j] = -1;
        for (int k = 0; k < 4; k++) {
            int x = i + dir1[k];
            int y = j + dir2[k];
            
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {                
                ans++;
                continue;
            }
            if (grid[x][y] == 0) {
                ans++;
                continue;
            }            
            if (grid[x][y] == -1) continue;
            dfs(x,y,grid);
        }
        return ;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                dfs(i,j,grid);
            }
        }
        return ans;
    }
    
};
