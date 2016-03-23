
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        int j = 0;
        int non_space = s.length() - 1;
        while (non_space >= 0) {
            if (s[non_space] == ' ')
                non_space --;
            else 
                break;
        }
        for (i = non_space; i >= 0; i --) {
            if (s[i] == ' ')
                break;
            else 
                j ++;
        }
        return j;
    }
};
