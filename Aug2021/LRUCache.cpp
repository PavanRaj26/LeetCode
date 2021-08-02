#include <stdio.h>

//Preorder
//Inorder

class LRUCache {
    
    deque<int> dq;
    unordered_map<int, deque<int>::iterator > mp;
    int cap;
    public:
    void refer();
    
}
LRUCache::LRUCache(int size) {
    cap = size;
}
void refer(int x) {
    
    if (mp.find(x) == mp.end()) {
        if (dq.size() == cap) {
            int v = dq.back();
            dq.pop_back();
            mp.erase(v);
        }
    } else {
        dq.erase(mp[x]);
    }
    dq.push_front(x);
    mp[x] = dq.begin();
    
}
int main() {
	//code
	
	return 0;
}