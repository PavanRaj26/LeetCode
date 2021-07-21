int recur(int i,int arr[],int pairs[],vector<int> &pos) {
        if (i == n) {
            return 0;
        }   
        if (arr[i] == pairs[arr[i+1]]) {
            return recur(i+2,arr,pairs,pos);
        }
        int dest = pos[pairs[a[i]]];
        swap(&a[i+1],&a[dest]);
        pos[a[i+1]] = i+1;
        pos[a[dest]] = dest;
        int x = 1 + recur(i+2,arr,pairs,pos);
        swap(&a[i+1],&a[dest]);
        pos[a[i+1]] = i+1;
        pos[a[dest]] = dest;
        
        dest = pos[pairs[a[i+1]]];
        swap(&a[i],&a[dest]);
        pos[a[i]]= i;
        pos[a[dest]] = dest;
        int y = 1 + recur(i+2,arr,pairs,pos);
        
        swap(&a[i],&a[dest]);
        pos[a[i]]= i;
        pos[a[dest]] = dest;
        
        return min(x,y);
        
    }
    int minSwapForArrangingPairs(int arr[],int pairs[]) {
        int n = arr.size();
        vector<int> pos(n+1);
        for (int i = 0; i < n i++) {
            pos[a[i]] = i;
        }
        return recur(0,arr,pairs,pos);
    }