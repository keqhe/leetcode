
/*
class TrieNode {
public:
    // Initialize your data structure here.
    vector<class TrieNode*> children;
    bool isLeaf;
    TrieNode() {
        children = vector<class TrieNode*> (26, NULL);
        isLeaf = false;
    }
};

//ref:https://leetcode.com/discuss/68924/ac-java-dfs-solution-beat-91-31%25-submissions

//this version has runt-time error, maybe stack overflow because of recursion
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void __insert(string &word, int i, struct TrieNode * r) {
        if (i == word.length()) {
            r->isLeaf = true;
            return;
        }
        char c = word[i];
        if (r->children[c - 'a'] == NULL) {
            r->children[c - 'a'] = new TrieNode();
        }
        __insert(word, i+1, r->children[c - 'a']);
    }
    // Inserts a word into the trie.
    void insert(string word) {
        __insert(word, 0, root);
    }

    bool __search(string &word, int i, struct TrieNode * r) {
        if (i == word.length() && r != NULL && r->isLeaf)
            return true;
        else if (r == NULL)
            return false;
        char c = word[i];
        return __search(word, i + 1, r->children[c - 'a']);
    }
    // Returns if the word is in the trie.
    bool search(string word) {
        return __search(word, 0, root);
    }

    bool __startsWith(string &prefix, int i, struct TrieNode* r) {
        if (i == prefix.length() && r != NULL)
            return true;
        if (r == NULL)
            return false;
        char c = prefix[i];
        return __startsWith(prefix, i + 1, r->children[c-'a']);
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return __startsWith(prefix, 0, root);
    }

private:
    TrieNode* root;
};
*/

////////////////////////////reference: https://leetcode.com/discuss/56123/c-c%23-simple-solution
/*
class TrieNode {
public:
    bool HasValue;
    TrieNode** Children;
    // Initialize your data structure here.
    TrieNode() {
        Children = new TrieNode*[26]();
        HasValue = false;
    }

    ~TrieNode(){
        for (int i = 0; i < 26; i++)
        {
            delete Children[i]; // delete NULL is safe, a no-op.
        }
        delete[] Children;
    }    
};*/

class TrieNode {
public:
    // Initialize your data structure here.
    vector<class TrieNode*> Children;
    bool HasValue;;
    TrieNode() {
        Children = vector<class TrieNode*> (26, NULL);
        HasValue = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        getNode(word, true)->HasValue = true;         
    }

    // Returns if the word is in the trie.
    bool search(string word) {
       TrieNode* pNode = getNode(word, false);
        return (pNode != NULL && pNode->HasValue);  
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return (getNode(prefix, false) != NULL); 
    }

private:
    TrieNode* root;
    TrieNode* getNode(string &word, bool create){
        TrieNode* pNode = root;
        int id;
        int n = word.size();
        for (int i = 0; i <n; ++i)
        {
          id = word[i] - 'a';
          if (pNode->Children[id] == NULL){
              if(create)
                pNode->Children[id] = new TrieNode();
              else
                return NULL;
          }
          pNode = pNode->Children[id];
        }

        return pNode;        
    }   
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
