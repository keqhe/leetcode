
class Solution {
public:
    
    string decodeString(string s) {
        string res;
        for (int i = 0; i < s.length(); ) {
            if (isdigit(s[i])) {
                int start = i;
                while (i < s.length() && isdigit(s[i])) {
                    i ++;
                }
                int count = stoi(s.substr(start, i-start));
                int left = 0;
                int j = i;
                start = j+1;
                for (; j < s.length(); j ++) {
                    if (s[j] == '[') {
                        left ++;
                    }
                    else if (s[j] == ']') {
                        left --;
                    }
                    if (left == 0) {
                        break;
                    }
                }
                
                string part = decodeString(s.substr(start, j-start));
                for (int k = 0; k < count; k ++) {
                    res += part;
                }
                i = j+1;
            }
            else {
                res += s[i];
                i ++;
            }
        }
        
        return res;
    }
};
