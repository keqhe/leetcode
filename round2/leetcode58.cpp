
class Solution {
public:
    int lengthOfLastWord(string s) {
        while (s.length() > 0 && s.back() == ' ') {
            s.pop_back();
        }
        if (s.empty())
            return 0;
        int len = 0;
        for (int i = s.length()-1; i >= 0; i --) {
            if (!isspace(s[i]))
                len ++;
            else
                break;
        }
        return len;
    }
};
