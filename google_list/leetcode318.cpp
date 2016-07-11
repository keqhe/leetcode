
class Solution {
public:
    int maxProduct1(vector<string>& words) {
        if (words.size() < 2)
            return 0;
        unordered_map<string, unsigned int> m;
        for (auto w : words) {
            int curr = 0;
            for (auto c : w) {
                curr |= (1 << (c-'a'));
            }
            m[w] = curr;
        }
        
        int maxValue = 0;
        for (int i = 0; i < words.size(); i ++) {
            for (int j = i+1; j < words.size(); j ++) {
                string word1 = words[i];
                string word2 = words[j];
                if ((m[word1] & m[word2]) == 0) {
                    maxValue = max(maxValue, (int)word1.length()*(int)word2.length());
                }
            }
        }
        return maxValue;
    }
    
    int maxProduct(vector<string>& words) {
        if (words.size() <= 1)
            return 0;
        int len = words.size();
        vector<unsigned int> tmp(len, 0);
        for (int i = 0; i < len; i ++) {
            string w = words[i];
            for (auto c : w) {
                tmp[i] |= (1 << (c - 'a'));
            }
        }
        int maxRes = 0;
        for (int i = 0; i < words.size(); i ++) {
            for (int j = i + 1; j < words.size(); j ++) {
                if ((tmp[i] & tmp[j]) == 0) {
                    int local = words[i].length()*words[j].length();
                    maxRes = max(maxRes, local);
                }
            }
        }
        return maxRes;
}
};
