
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1;
        int pos2 = -1;
        int last_appear = -1;
        
        int dist = words.size()+1;
        
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) {
                pos1 = i;
                
                if (last_appear != -1) {
                    dist = min(dist, abs(pos1-last_appear));
                }
                last_appear = i;
            }
            else if (words[i] == word2) {
                pos2 = i;
            }
            
            if (word1 != word2) {
                if (pos1 >= 0 && pos2 >= 0) {
                    dist = min(dist, abs(pos1-pos2));
                }
            }
        }
        return dist;
    }
};
