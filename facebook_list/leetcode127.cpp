
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        unordered_set<string> used;
        used.insert(beginWord);
        while (!q.empty()) {
            int size = q.size();
            level ++;
            for (int i = 0; i < size; i ++) {
                string curr = q.front();
                q.pop();
                for (int j = 0; j < curr.length(); j ++) {
                    for (char c = 'a'; c <= 'z'; c ++) {
                        string tmp = curr;
                        tmp[j] = c;
                        if (curr == tmp)
                            continue;
                        if (wordList.find(tmp) != wordList.end() && used.find(tmp) == used.end()) {
                            if (tmp == endWord)
                                return level;
                            else {
                                q.push(tmp);
                                used.insert(tmp);
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};
