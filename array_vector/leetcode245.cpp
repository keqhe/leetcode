
class Solution {
public:
    //the difference from "shortest word distance I" is that word1 and word2 may be the same
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        int minDist = words.size()+1;
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) {
                if (index2 != -1) {
                    minDist = min(minDist, i-index2);
                }
                index1 = i;
                if (word1 == word2)
                    index2 = i;
            }
            else if (words[i] == word2) {
                if (index1 != -1) {
                    minDist = min(minDist, i-index1);
                }
                index2 = i;
                if (word1 == word2)
                    index1 = i;
            }
        }
        return minDist;
    }
};
