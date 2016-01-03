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

    // Inserts a word into the trie.
    void insert(string word) {
	getNode(word,true)->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return (getNode(word,false) != NULL) && (getNode(word,false)->isLeaf == true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
	return getNode(prefix,false) != NULL;
    }

private:
    TrieNode* root;
    struct TrieNode * getNode(string & word, bool create) {
	struct TrieNode * r = root;
	for (int i = 0; i < word.size(); i ++) {
		int c = word[i] - 'a';
		if (r->children[c] == NULL) {
			if (create)
				r->children[c] = new TrieNode();
			else 
				return NULL;
		}
		r = r->children[c];
	}
	return r;
    }
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
