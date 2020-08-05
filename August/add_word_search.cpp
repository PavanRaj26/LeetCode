class WordDictionary {
    private:
    unordered_map<string,int> processed;
    unordered_map<string,int> mp;
    struct Node {
        bool isEnd;
        vector<Node *> v{26};
    };
    Node *head;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = newNode();          
    }
    /** Adds a word into the data structure. */
    Node *newNode() {
        Node * nn = new Node();
        for (int i =0 ; i < 26; i++) {
            nn->v[i] = NULL;
        }
        nn->isEnd = false;
        return nn;
    }
    void addWord(string word) {
        
        int n = word.size();
        Node *ptr = head;
        for (int i = 0;i < n; i++) {
            int no = word[i] - 'a';
            if (ptr->v[no] == NULL)  {
                ptr->v[no] = newNode();   
            }                
            ptr = ptr->v[no];
        }
        ptr->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(head,word,0);
    }
     bool find(Node *cur,string word,int idx) {
        if (idx == word.size()) return cur->isEnd;
        if (word[idx] == '.') {
            
            for (int i =0 ;i < 26; i++) {
                if (cur ->v[i]) {
                    if (find(cur->v[i],word,idx+1)) {
                        return true;
                    }
                }
            }
            return false;
        }
        int no = word[idx] - 'a';
        if (cur->v[no]) {
            return find(cur->v[no],word,idx+1);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
