
class Solution {
public:
    //idea, first reverse the whole string, then reverse each word
    //"hello world!"-> "!dlrow olleh"->"world! hello"
    void myreverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
    void reverseWords(string &s) {
        if (s.empty() || s.length() == 1)
            return;
        myreverse(s, 0, s.length() - 1);
        int j = 0;
        int i = 0;
        for (i = 0; i < s.length(); i ++) {
            if (isspace(s[i])) {
                myreverse(s,j, i-1);
                j = i + 1;
            }
        }
        //last word
        myreverse(s,j, i-1);
    }
};
