
class Solution {
public:
    //string functions, isnum, isalpha, isalnum, isspace, toupper, tolower, isupper, islower
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int left = 0;
        int right = s.length()-1;
        while (left < right) {
            while (!isalnum(s[left]))
                left ++;
            while (!isalnum(s[right]))
                right --;
            if (left < right) {
                if (tolower(s[left]) == tolower(s[right])) {
                    left ++;
                    right --;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
