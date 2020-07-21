
class Solution {
    
    string word;
    int vis[201][201];
public:
    bool dfs(vector<vector<char> > &board,int idx,int i,int j) {
        if (word[idx] == '\0') return true;
        if (i <0 || i >= board.size()) return false;
        if (j <0 || j >= board[0].size()) return false;
        if (vis[i][j] == 1 || word[idx] != board[i][j]) {
            return false;
        }
        vis[i][j] = 1;
        if (dfs(board, idx + 1, i + 1, j))
			return true;
		if (dfs(board, idx + 1, i - 1, j))
			return true;
		if (dfs(board, idx + 1, i, j + 1))
			return true;
		if (dfs(board, idx + 1, i, j - 1))
			return true;
		vis[i][j] = 0;
        return false;
    }    
    bool exist(vector<vector<char>>& board, string w) {
        int n= board.size();
        if (n == 0) return false;
        int m = board[0].size();
        word = w;
        for (int i= 0; i <n; i++) {
            for (int j = 0;j < m; j++) {
                if (board[i][j] == word[0]) {
                    if(dfs(board,0,i,j))
                        return true;
                }        
            }            
        }
        return false;
    }
};
