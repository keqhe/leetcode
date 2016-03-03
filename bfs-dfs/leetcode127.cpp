#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        unordered_set<string> used;
        queue<pair<string, int>> q;
        int level;
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            pair<string, int> tmp = q.front();
            q.pop();
            string s = tmp.first;
            level = tmp.second;
            used.insert(s);
            for (int i = 0; i < s.length(); i ++) {
                for (char c = 'a'; c <= 'z'; c ++) {
                    if (s[i] != c) {
                        char record = s[i];
                        s[i] = c;
                        if (s == endWord)
                            return level+1;
                        if (wordList.find(s) != wordList.end() && used.find(s) == used.end()) {
                            q.push(make_pair(s, level+1));
                            used.insert(s);//forgot this initially...
                        }
                        s[i] = record;
                    }
                }
            }
        }
        
        return 0;
    }
};

int main() {
	class Solution sn;
	return 0;
}
