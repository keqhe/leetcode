#include<vector>
#include<string>

using namespace std;

struct TrieNode {
  bool isEnd;
  vector<struct TrieNode*> children;
  TrieNode() {
      isEnd = false;
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
        struct TrieNode * p = root;
        for (int i = 0; i < word.length(); i ++) {
            int index = word[i] - 'a';
            if (!p->children[index])
                p->children[index] = new TrieNode();
            p = p->children[index];
        }
        p->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool helper(string word, struct TrieNode * p) {
        if (!p)
            return false;
        if (word.empty())
            if (p->isEnd)
                return true;
            else
                return false;

        if (word.front() != '.') {
            int index = word.front() - 'a';
            return helper(word.substr(1), p->children[index]);
        }
        else {
            bool tmp = false;
            string str = word.substr(1);
            for (int i = 0; i < 26 && !tmp; i ++) {
                tmp |= helper(str, p->children[i]);
            }
            return tmp;
        }
    }
    bool search(string word) {
        return helper(word, root);
    }
private:
    struct TrieNode * root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
	class WordDictionary dict;
	return 0;
}
