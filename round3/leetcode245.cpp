
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, int> m;
        int minDist = numeric_limits<int>::max();
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) {
                if (m.find(word2) != m.end()) {
                    minDist = min(minDist, i-m[word2]);
                }
            }
            else if (words[i] == word2) {
                if (m.find(word1) != m.end()) {
                    minDist = min(minDist, i-m[word1]);
                }
            }
            m[words[i]] = i;
        }
        return minDist;
    }
};
