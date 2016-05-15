
class TrieNode {
public:
    // Initialize your data structure here.
    /*TrieNode() {
        bool isLeaf;
        vector<class TrieNode*> children;
        TrieNode() {
            isLeaf = false;
            children.resize(26, NULL);
        }
    }*/
    vector<class TrieNode*> children;
    bool isLeaf;
    TrieNode() {
        isLeaf = false;
        children.resize(26, NULL);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        class TrieNode * p = root;
        for (int i = 0; i < word.length(); i ++) {
            int index = word[i] - 'a';
            if (p && !p->children[index]) {
                p->children[index] = new TrieNode();
            }
            p = p->children[index];
        }
        p->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        class TrieNode * p = root;
        for (int i = 0; i < word.length(); i ++) {
            int index = word[i] - 'a';
            if (!p || !p->children[index])
                return false;
            p = p->children[index];
        }
        return p->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        class TrieNode * p = root;
        for (int i = 0; i < prefix.length(); i ++) {
            int index = prefix[i] - 'a';
            if (!p || !p->children[index])
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
