
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m;
        m['0'] = '0';
        m['1'] = '1';
        m['8'] = '8';
        m['6'] = '9';
        m['9'] = '6';
        string tmp;
        for (int i = 0; i < num.length(); i ++) {
            if (m.find(num[i]) != m.end())
                tmp.push_back(m[num[i]]);
            else 
                return false;
        }
        reverse(num.begin(), num.end());
        return num == tmp;
    }
};
