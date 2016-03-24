
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty() || s.size() == 1)
            return true;
        int i = 0;
        int j = s.length() -1;
        while (i < j) {
            while (!isalnum(s[i]))
                i ++;
            while (!isalnum(s[j]))
                j --;
            if (i < j) {
                if (tolower(s[i]) == tolower(s[j])) {
                    i ++;
                    j --;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
