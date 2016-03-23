
class Solution {
public:
    void reverseWords(string &s) {
        string res;
        
        for (int i = s.length() - 1; i >= 0;) {
            while (i >= 0 && isspace(s[i])) {
                i --;
            }
            if (i < 0) break;
            if (!res.empty()) res += ' ';
            string temp;
            while (i >= 0 && !isspace(s[i])) {
                temp.push_back(s[i]);
                i --;
            }
            reverse(temp.begin(), temp.end());
            res.append(temp);
        }
        
        s = res;
    }
};
