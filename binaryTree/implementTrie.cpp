#include<iostream>
#include<string>
#include<vector>

using namespace std;

//i met this error before: http://stackoverflow.com/questions/11490988/c-compile-time-error-expected-identifier-before-numeric-constant
class TrieNode {
public:
    // Initialize your data structure here.
    //vector<class TrieNode*> children(26); //this is WRONG!!!
    //vector<class TrieNode*> children = vector<class TrieNode*>(26, NULL);//method 1
    vector<class TrieNode*> children;
    bool isLeaf;
    TrieNode() {
 	//or you can initialize children here
	children = vector<class TrieNode*>(26, NULL);       
	isLeaf = false;
    }
    ~TrieNode() {
    }
};

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
	if (r == NULL)
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

int main() {
	class Trie trie;
	trie.insert("good");
	cout << trie.search("good") << endl;
	cout << trie.startsWith("g") << endl;

	string test = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	for (char i = 'a'; i <= 'z'; i ++) {
		string temp = test;
		temp.push_back(i);
		trie.insert(temp);
	}
	cout << trie.search(test) << endl;
	cout << trie.search(test+"c") << endl;
	cout << trie.startsWith(test) << endl;	
	cout << trie.startsWith("a") << endl;
	return 0;
}
