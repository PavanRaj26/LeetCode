class StreamChecker {
    private:
    string soFar;
    struct Node {
        bool isEnd;
        vector<Node*> v{26};
    };
    Node *head;    
public:
    Node *newNode() {
        Node *nn = new Node();
        nn->isEnd = false;
        for (int i =0; i< 26; i++) nn->v[i]= NULL;
        return nn;
    }
    void insert(string s) {
        
        Node *cur = head;
        reverse(s.begin(),s.end());
        for (int i =0; i < s.size(); i++) {
            int no = s[i] - 'a';
            if (cur->v[no] == NULL) {
                cur->v[no] = newNode();
            }
            cur = cur->v[no];
        }
        cur->isEnd = true;
        return;
    }
    bool isSuffix() {
        Node*cur = head;
        for (int i =soFar.size()-1 ; i >= 0; i--) {
            int no = soFar[i] - 'a';
            if (cur->isEnd) {
                return true;
            }if (cur ->v[no] == NULL) {
                return false;
            }
               
            cur = cur ->v[no];
        }
        if (cur ->isEnd) return true;
        return false;        
    }
    StreamChecker(vector<string>& words) {
        head = newNode();        
        for (int i =0; i < words.size(); i++) {
            insert(words[i]);
        }
    }
    
    bool query(char letter) {
        string r(1,letter);
        soFar += r;
        return isSuffix();
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
