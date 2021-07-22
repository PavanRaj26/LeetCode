void dfs(int i,int key) {
        if (i == key) {
            cnt++;
            return;
        }
        list<int>::iterator it = adj[i].begin();
        for (; it!= adj[i].end(); it++) {
            int x = (*it);
            dfs(x);
        }
        return;
    }
    int countPossiblePaths(int src) {
    
        dfs(src);
        return cnt;
    }