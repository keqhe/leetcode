
//ref: https://leetcode.com/discuss/91429/solution-with-structure-total-number-words-average-length
bool isPal(string s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i ++;
        j --;
    }
    return true;
}
class TrieNode {
public:
    short index;//the index of the word is the represented by current node [root..curr)
    vector<class TrieNode*> children;
    list<int> l;//the indices of the words whose [0..curr] is Palindrome
    TrieNode() {
        index = -1;
        //children.resize(256, NULL);//256 chars, Memeory limit exceeds...
        children.resize(26, NULL);//only assume we use "a" to "z"
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    //insert word
    void insert(string word, int index) {
        class TrieNode * p = root;
        for (int i = word.length()-1; i >= 0; i --) {
            if (isPal(word, 0, i))//think why it is not "i-1"
                p->l.push_back(index);//think why, that means the rest of word is palindrome
            char c = word[i];
            if (!p->children[c-'a'])
                p->children[c-'a'] = new TrieNode();
            p = p->children[c-'a'];
        }
        p->index = index;//think why
        p->l.push_back(index);//think why, empty string is also Palindrome
    }
    void search(string word, int index, vector<vector<int>> & res) {
        class TrieNode * p = root;
        for (int i = 0; i < word.length(); i ++) {
            if (p->index >= 0 && p->index != index && isPal(word, i, word.length()-1)) {
                //that means there exists some word x where word[0..i) == x[len-i, len-1]
                //and word[i, word.len-1] is palindrome
                //so word+x must be palindorme
                //in this case len(word) > len(x)
                vector<int> tmp = {index, p->index};//make sure it is distinct
                res.push_back(tmp);
            }
            char c = word[i];
            p = p->children[c-'a'];
            if (!p)
                return;
        }
        for (int j : p->l) {
            if (index == j)
                continue;
            vector<int> tmp = {index, j};//in this case len(word) <= len(x)
            res.push_back(tmp);
        }
    }
private:
    class TrieNode * root;
};
class Solution {
public:
    //the naive solution's time complexity is O(n^2*k), where n is the number of words and k is the word length
    vector<vector<int>> palindromePairs_Okay(vector<string>& words) {
        vector<vector<int>> res;
        if (words.size() < 2)
            return res;
        class Trie tr;
        for (int i = 0; i < words.size(); i ++) {
            tr.insert(words[i], i);
        }
        
        for (int i = 0; i < words.size(); i ++) {
            tr.search(words[i], i, res);
        }
        return res;
    }
    //the following just for AC purpose
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        if (words.empty())
            return res;
        unordered_map<string,int> m;
        unordered_set<string> se;
        for (int i = 0; i < words.size(); i ++)
            m[words[i]] = i;
        vector<int> tmp(2);
        for (int i = 0; i < words.size(); i ++) {
            string curr = words[i];
            string prefix = curr;
            string suffix = curr;
            int K = curr.length();
            for (int len = 0; len <= K; len ++) {
                if (isPal(prefix, 0, len-1)) {
                    string rest = prefix.substr(len);
                    reverse(rest.begin(), rest.end());
                    if (m.find(rest) != m.end()) {
                        tmp[0] = m[rest];
                        tmp[1] = i;
                        string key = to_string(tmp[0]) + "-"+ to_string(tmp[1]);
                        if (tmp[0] != tmp[1] && se.find(key) == se.end()) {
                            res.push_back(tmp);
                            se.insert(key);
                        }
                    }
                }
                if (isPal(suffix, len, K-1)) {
                    string rest = suffix.substr(0, len);
                    reverse(rest.begin(), rest.end());
                    if  (m.find(rest) != m.end()) {
                        tmp[1] = m[rest];
                        tmp[0] = i;
                        string key = to_string(tmp[0]) + "-"+ to_string(tmp[1]);
                        if (tmp[0] != tmp[1] && se.find(key) == se.end()) {
                            res.push_back(tmp);
                            se.insert(key);
                        }
                    }
                }
            }
        }
        
        return res;
    }
};
