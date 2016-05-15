
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> used;
        wordList.insert(endWord);
        queue<string> q;
        q.push(beginWord);
        used.insert(beginWord);
        
        bool found = false;
        int len = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                string curr = q.front();
                q.pop();
                
                for (int j = 0; j < curr.length(); j ++) {
                    char c = curr[j];
                    string tmp = curr;
                    for (char x = 'a'; x <= 'z'; x ++) {
                        if (x == c)
                            continue;
                        tmp[j] = x;
                        if (wordList.find(tmp) != wordList.end()) {
                            if (tmp == endWord) {
                                found = true;
                            }
                            else {
                                if (used.find(tmp) == used.end()) {
                                    used.insert(tmp);
                                    q.push(tmp);
                                }
                            }
                        }
                    }
                }
            }
            len ++;
            if (found)
                return len;
        }
        if (found == false)
            return 0;
        else
            return len;//just a place holder; i do not think this is really excuted
    }
};
