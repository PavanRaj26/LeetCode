int search(int key,int in[]) {
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == key) return i;
    }
    return 0;
}
void recur(int in[],int pre[],int n) {
    int idx = search(pre[i],in);
    if (idx!=0)
        recur(in,pre+1,idx);
    if (idx != n - 1)
        recur(in+idx+1,pre+idx+1,n-idx-1);
    printf("pre[0]");
}
void recur(int mn,int mx,int idx,int n) {
    if (idx == n) {
        return;
    }
    int val = pre[idx++];
    if (val < mn || val > mx) return;
    recur(mn,val,idx);
    recur(val,mx,idx);
    printf("val");
}