
class Solution {
public:
    //the sky is blue
    //eht yks si eulb
    //blue is sky the
    void reverseWords(string &s) {
        if (s.empty())
            return;
        int i = 0;
        int j = 0;
        while (i < s.length()) {
            while (i < s.length() && s[i] != ' ')
                i ++;
            reverse(s.begin()+j, s.begin()+i);
            while (i < s.length() && s[i] == ' ')
                i ++;
            j = i;
        }
        reverse(s.begin(), s.end());
    }
};
