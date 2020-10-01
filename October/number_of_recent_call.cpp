class RecentCounter {
    private:
    set<int> S;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        S.insert(t);
        set<int>::iterator it = S.lower_bound(t - 3000);
        int dis = distance(it,S.end());
        return dis;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
