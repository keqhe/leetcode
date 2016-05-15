
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int start = 0;
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int cnt = 0;
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] == ' ' || i+1 == str.length()) {
                string curr;
                if (i+1 < str.length())
                    curr = str.substr(start, i-start);
                else
                    curr = str.substr(start, i+1-start);
                start = i+1;
                if (cnt < pattern.length()) {
                    if (m1.find(pattern[cnt]) == m1.end()) {
                        m1[pattern[cnt]] = curr;
                    }
                    else {
                        if (m1[pattern[cnt]] != curr)
                            return false;
                    }
                    if (m2.find(curr) == m2.end()) {
                        m2[curr] = pattern[cnt];
                    }
                    else {
                        if (m2[curr] != pattern[cnt])
                            return false;
                    }
                }
                else
                    return false;
                cnt ++;
            }
        }
        cout << "debug" << endl;
        string res;
        for (auto c : pattern) {
            res += m1[c] + ' ';
        }
        if (!res.empty())
            res.pop_back();
        cout << res << endl;
        if (res != str)
            return false;
        return true;
    }
};
