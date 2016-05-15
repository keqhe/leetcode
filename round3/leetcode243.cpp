
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        int minDist = numeric_limits<int>::max();
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) {
                if (index2 != -1) {
                    minDist = min(minDist, i-index2);
                }
                index1 = i;
            }
            else if (words[i] == word2) {
                if (index1 != -1) {
                    minDist = min(minDist, i-index1);
                }
                index2 = i;
            }
        }
        return minDist;
    }
};
