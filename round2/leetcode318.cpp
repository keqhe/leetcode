
class Solution {
public:
    //ref: https://leetcode.com/discuss/90449/java-35ms-solution-using-bitmap
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
