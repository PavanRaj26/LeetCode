class CombinationIterator {
    private:
    string s;
    int cnt ;
    map<string,int> mp;
    int sz;
    int n;
    map<string,int>::iterator it;
public:
    void recur(int idx,string t,int mask) {
        if (idx == sz) {
            cout << t <<endl;
            mp[t] = 1;
            cnt++;
            return ;
        }
        if (cnt > 10000) {
                return;
        }
        int j=-1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                j = i;
            }
        }
        
        for (int i =j + 1 ;i < n; i++) {
           if (mask & (1<<i)) {
               continue;
           }   
           mask |= (1<<i);
           string r(1,s[i]);
           t += r;
           recur(idx+1,t,mask);
           mask = mask &~(1<<i);  
           t.pop_back();
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        n = characters.size();
        sz = combinationLength;
        recur(0,"",0);
        it = mp.begin();        
    }
    
    string next() {
        map<string,int>::iterator it1 = it;
        it++;
        return (*it1).first;
        
    }
    
    bool hasNext() {
        if (it == mp.end()) {
            return false;
        }
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
