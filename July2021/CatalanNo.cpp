int catalanNo(Node *root) {
        
        int c[100];
        c[0] = 0;
        c[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0;j < i; j++) {
                c[i] += c[j] * c[i-j-1];
            }
        }
        return c[n];
    }