
class Solution {
public:
    //reverse the string two times
    //https://leetcode.com/discuss/73274/share-my-in-place-solution-by-reversing-the-string-two-times
    void reverseWords(string &s) {
        if (s.empty())
            return;
        int start = 0;
        bool comp = false;
        for (int i = 0; i < s.length(); i ++) {
            if (isspace(s[i])) {
                reverse(s.begin()+start, s.begin() + i);
                //Reverses the order of the elements in the range [first, last)
                
                start = i + 1;
                comp = true;// does s have more than 1 word?
            }
        }
        if (comp == true) {//the last word
            reverse(s.begin()+start, s.end());
        }
        if (comp)
            reverse(s.begin(), s.end());
    }
};
