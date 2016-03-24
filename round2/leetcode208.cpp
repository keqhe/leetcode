
class TrieNode {
public:
    // Initialize your data structure here.
    vector<class TrieNode*> children;
    bool isEnd;
    TrieNode() {
        isEnd = false;
        children.resize(26, NULL);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    //what about empty string ""?, it seems that we do not need to consider ""?
    // Inserts a word into the trie.
    void insert(string word) {
        class TrieNode * p = root;
        for (int i = 0; i < word.length(); i ++) {
            int index = word[i] - 'a';
            if (!p->children[index]) {
                p->children[index] = new TrieNode();
            }
            p = p->children[index];
        }
        p->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        class TrieNode * p = root;
        for (int i = 0; i < word.length(); i ++) {
            int index = word[i] - 'a';
            if (!p->children[index])
                return false;
            p = p->children[index];
        }
        return p->isEnd == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    
    bool startsWith(string prefix) {
        class TrieNode * p = root;
        for (int i = 0; i < prefix.length(); i ++) {
            int index = prefix[i] - 'a';
            if (!p->children[index])
                return false;
            p = p->children[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
