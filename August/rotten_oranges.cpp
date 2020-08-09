class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int mx = -1;
        int n = grid.size();
        int m = grid[0].size();
        int f = 0;
        bool isFresh = false;
        bool isOrange =  false;
        for (int i =0;i< n; i++) {
            for (int j =0;j < m;j++) {
                if (grid[i][j]==2) {
                    isOrange = true;
                }
                if (grid[i][j] == 1) {
                    isFresh = true;                
                }
            }
        }
        if (!isFresh) {
            return 0;
        }
        if (!isOrange) {
            return -1;
        }
        for (int i= 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 || grid[i][j] == 2) continue;
                f = 1;
                queue< pair< pair<int,int> ,int> > Q;
                Q.push(make_pair(make_pair(i,j),0));
                vector< vector<int> > vis(n,vector<int>(m,1));
                int lev = -1;
                while (!Q.empty()) {
                pair< pair<int,int> ,int> pp = Q.front();
                        Q.pop();
                    int x = pp.first.first;
                    int y = pp.first.second;
                    vis[x][y] = 0;
                    if (x != 0) {
                        
                        if (vis[x-1][y] && grid[x-1][y] == 1) {
                            Q.push(make_pair(make_pair(x-1,y),pp.second+1));
                        }
                        if (grid[x-1][y] == 2) {
                            lev = pp.second+1;
                            break;
                        }                    
                    }    
                    if (y != 0) {
                        if (vis[x][y-1] && grid[x][y-1] == 1) {
                            Q.push(make_pair(make_pair(x,y-1),pp.second+1));
                        }
                        if (grid[x][y-1] == 2) {
                            lev = pp.second+1;
                            break;
                        }
                    }
                   if (x != n - 1) {
                       if (vis[x+1][y] && grid[x+1][y] == 1) {
                            Q.push(make_pair(make_pair(x+1,y),pp.second+1));
                        }
                        if (grid[x+1][y] == 2) {
                            lev = pp.second+1;
                            break;
                        }
                   } 
                   if (y != m - 1) {
                       if (vis[x][y+1] && grid[x][y+1] == 1) {
                            Q.push(make_pair(make_pair(x,y+1),pp.second+1));
                        }
                        if (grid[x][y+1] == 2) {
                            lev = pp.second+1;
                            break;
                        }
                   } 
                }
                    if (lev == -1) return -1;
                    mx = max(mx,lev);

            }
        }
        if (f) 
            return mx;
        else 
            return 0;
    }
};
