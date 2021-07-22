public:
    //Function to find out minimum steps Knight needs to reach target position.
	int dx[8] = {2,1,-2,-1,-2,-1,2,1};
	int dy[8] = {1,2,1,2,-1,-2,-1,-2};
	
	bool isValid(int i,int j,int N) {
	    if (i > N || j > N) return false;
	    if (i <= 0 || j <= 0) return false;
	    return true;
	}
    struct Cell {
        int i,j,dist;
        Cell(int i,int j,int dist) : i(i),j(j),dist(dist) {} 
    };
	int minStepToReachTarget(vector<int>&KPos,vector<int>&TPos,int N)
	{
	    // Code here
	    if (N == 1) return 0;
	    bool vis[N+1][N+1];
	    memset(vis,false,sizeof(vis));
	    queue<Cell> Q;
	    Q.push(Cell(KPos[0],KPos[1],0));
	    while (!Q.empty()) {
	        Cell c = Q.front();
	        Q.pop();
	        if (c.i == TPos[0] && c.j == TPos[1]) {
	            return c.dist;
	        }
	       
	        int i = c.i;
	        int j = c.j;
	        if (vis[i][j]) continue;
	        vis[i][j] = true;
	        for (int k = 0; k < 8; k++) {
	            int x = i + dx[k];
	            int y = j + dy[k];
	            if (isValid(x,y,N) && !vis[x][y]) {
	                
	                Q.push(Cell(x,y,c.dist+1));
	            }
	        }
	    }
	    return -1;
	}