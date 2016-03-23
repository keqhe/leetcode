
class Solution {
public:
    //
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1;
        int pos2 = -1;
        int res = words.size();
        for (int i = 0; i < words.size(); i ++) {
            if(words[i] == word1)
                pos1 = i;
            else if (words[i] == word2)
                pos2 = i;
            else 
                continue;
            if (pos1 >= 0 && pos2 >= 0 && abs(pos1-pos2) < res) {
                res = abs(pos1-pos2);
            }
        }
        return res;
    }
};
