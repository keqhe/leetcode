
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";//made a mistake here, s = '1', it must be string not char
        if (n == 1)
            return s;
        for (int i = 2; i <= n; i ++) {
            string ns;
            for (int j = 0; j < s.length();) {
                unsigned long count = 1;
                string pre;
                for (int k = j + 1; k < s.length(); k ++) {
                    if (s[k] == s[k - 1]) {
                        count ++;
                    }
                    else {
                        break;
                    }
                }
                pre = to_string(count);//made a mistake here, used stoul
                ns += pre + s[j];
                j += count;
            }
            
            s = ns;
        }
        return s;
    }
};
