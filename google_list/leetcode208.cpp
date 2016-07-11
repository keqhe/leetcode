
class TrieNode {
public:
    bool isLeaf;
    vector<TrieNode*> children;
    // Initialize your data structure here.
    TrieNode() {
       isLeaf = false;
       children.resize(26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto p = root;
        for (auto c : word) {
            int index = c - 'a';
            if (p && !p->children[index])
                p->children[index] = new TrieNode();
            p = p->children[index];
        }
        p->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto p = root;
        for (auto c : word) {
            int index = c - 'a';
            if (p && !p->children[index])
                return false;
            p = p->children[index];
        }
        return p->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c : prefix) {
            int index = c - 'a';
            if (p && !p->children[index])
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
