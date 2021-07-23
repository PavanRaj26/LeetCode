int N = 64;
int board[N+1][N+1];

bool isValid(int row,int col) {
	
	for (int i = 0; i < col; i++) {
		if (board[row][col] == 1) return false;
	}
	int i,j;
	for (i = row,j = col; i >=0 && j >= 0; i--,j--) {
		if (board[i][j] == 1) return false;
	}
	for (i = row, j = col;i < N && j >= 0; i++,j--) {
		if (board[i][j] == 1) return false;
	}
	return true;
}
bool NQueen(int col) {
		if (col >= N) {
			for (int i = 0; i < N; i++) {
				for (int j = 0;j < N: j++) {
					cout << board[i][j] <<" ";
				}
				cout << endl;
			}
			return true;
		}
		for (int ro = 0; ro < N; ro++) {
			if (isValid(ro,col)) {
				board[ro][col] = 1;
				if (NQueen(col+1)) return true;
				board[ro][col] = 0;
			}
		}
		return false;
}