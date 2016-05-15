
class Solution {
public:
    int lengthOfLastWord(string s) {
        while (s.length() > 0) {
            if (isspace(s.back()))
                s.pop_back();
            else
                break;//i often forget this when processing tailing spaces in string
        }
        if (s.empty())
            return 0;
        int i = s.length() - 1;
        cout << i << endl;
        while (!isspace(s[i])) {
            i --;
            if (i == -1)
                break;
        }
        return s.length()-1-i;
    }
};
