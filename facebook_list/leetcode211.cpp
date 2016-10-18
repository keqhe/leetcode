
class TrieNode {
public:
    TrieNode() {
        isLeaf = false;
        children.resize(26, nullptr);
    }
    bool isLeaf;
    vector<TrieNode*> children;
};

class WordDictionary {
public:
    WordDictionary() {
       root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
       auto p = root;
       for (auto c : word) {
           int index = c - 'a';
           if (!p->children[index]) {
               p->children[index] = new TrieNode();
           }
           p = p->children[index];
       }
       p->isLeaf = true;
       std::cout << "good" << endl;
    }
    bool match(string s, TrieNode* p) {
        if (s.empty() && p && p->isLeaf)
            return true;
        if (!p)
            return false;
        if (s.empty())
            return false;
        char c = s.front();
        if (c != '.') {
            int index = c - 'a';
            if(match(s.substr(1), p->children[index])) {
                return true;
            }
        }
        else {
            for (int i = 0; i < 26; i ++) {
                if (match(s.substr(1), p->children[i]))
                    return true;
            }
        }
        return false;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return match(word, root);
    }
private:
    TrieNode * root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
