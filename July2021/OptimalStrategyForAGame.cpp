int optimalStrategyForGame(int arr[]) {
        int n = arr.size();
        int dp[n+1][n+1];
        for (int i = 0; i < n; i++) dp[i][i] = arr[i];
        for (int gap = 1; gap < n; gap++) {
            for (int i = 0,j = gap; i + j < n; i++,j++) {
                int x,y,z;
                x = ((i+2)<=j?dp[i+2][j]:0);
                y = ((i+1)<=(j-1)?dp[i+1][j-1]:0);
                z = (i <= (j - 2)?dp[i][j-2]:0);
                dp[i][j] = max(a[i] + min(x,y),a[j] + min(y,z));
            }
        }
        return dp[0][n-1];
    }