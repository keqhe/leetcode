
//for all the trie based problem, we assume we only use char from 'a' to 'z'
class TrieNode {
public:
    bool isLeaf;
    vector<class TrieNode*> children;
    TrieNode() {
        isLeaf = false;
        children.resize(26, NULL);
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        class TrieNode * p = root;
        for (int i = 0; i < word.length(); i ++) {
            int index = word[i] - 'a';
            if (p && !p->children[index])
                p->children[index] = new TrieNode();
            p = p->children[index];
        }
        p->isLeaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return helper(word, root);
    }
    
    bool helper(string word, class TrieNode * p) {
        if (!p)
            return false;
        if (word.empty() && p->isLeaf)
            return true;
        if (word.empty())
            return false;
        char c = word.front();
        if (c != '.') {
            int index = c - 'a';
            if (!p->children[index])
                return false;
            return helper(word.substr(1), p->children[index]);
        }
        else {
            for (int i = 0; i < 26; i ++) {
                if (helper(word.substr(1), p->children[i]))
                    return true;
            }
            return false;
        }
    }
private:
    class TrieNode * root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
