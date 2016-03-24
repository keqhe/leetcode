
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        if (s == "B")
            return 2;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                res = res*26 + s[i] - 'A'+1;
            if (s[i] >= 'a' && s[i] <= 'z')
                res = res*26 + s[i] - 'a'+1;
        }
        return res;
    }
};
