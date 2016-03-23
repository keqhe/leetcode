
struct Trie {
    bool isWord;
    vector<struct Trie*> children;
    Trie() {
        isWord = false;
        children = vector<struct Trie*> (26, NULL);
    }
};
//ref: https://leetcode.com/discuss/40409/c-clean-code-using-trie
class WordDictionary {
public:
    struct Trie * root;
    
    WordDictionary() {
        root = new Trie();//do we need to initialize root here?
    }
    //what about memory cleanup?
    void cleanup (struct Trie * r) {
        if (!r)
            return;
        for (int i = 0; i < r->children.size(); i ++) {
            cleanup(r->children[i]);
        }
        delete r;
    }
    ~WordDictionary() {
        cleanup(root);
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        struct Trie * curr = root;
        int index;
        for (int i = 0; i < word.length(); i ++) {
            index = word[i] - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new Trie();
            }
            curr = curr->children[index];
        }
        curr->isWord = true;//(the word's) leaf->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    
    //dfs
    bool helper(string & word, int index, struct Trie * r) {
        if (!r)
            return false;
        if (index == word.length()) {
            if (r->isWord == true)
                return true;
            else
                return false;
        }
        
        if (word[index] == '.') {
            for (int i = 0; i < 26; i ++) {
                if (helper(word, index+1, r->children[i]))
                    return true;
            }
            return false;
        }
        else {
            return helper(word, index+1, r->children[word[index]-'a']);
        }
    }
    bool search(string word) {
        return helper(word, 0, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
