
class Solution {
public:
    //use an interger to record whether a letter appears in the word, note if all words are using lower case letters, then there are 26 possible letter, so an 32 integer is enough
    int maxProduct(vector<string>& words) {
        if (words.size() < 2)
            return 0;
        vector<int> letters(words.size(), 0);
        for (int i = 0; i < words.size(); i ++) {
            for (char c : words[i]) {
                letters[i] |= (1 << (c-'a'));
            }
        }
        int maxProduct = 0;
        for (int i = 0; i < words.size(); i ++) {
            for (int j = i + 1; j < words.size(); j ++) {
                if ( (letters[i]&letters[j]) == 0) {//no common letter
                    maxProduct = max(maxProduct, (int)words[i].length()*(int)words[j].length());
                }
            }
        }
        return maxProduct;
    }
};
