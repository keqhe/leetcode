
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;//if the test case is "AAAAAAAAAAAA", de-dup
        unordered_set<string> se;
        for (int i = 0; i+10 <= s.length(); i ++) {
            string str = s.substr(i, 10);
            if (se.find(str) != se.end())
                res.insert(str);
            else
                se.insert(str);
        }
        vector<string> tmp (res.begin(), res.end());
        return tmp;
    }
};
