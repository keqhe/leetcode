
class Solution {
public:
    //in C++, STL containers are not thread-safe
    //
    //reference: http://www.programcreek.com/2014/03/leetcode-repeated-dna-sequences-java/
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() < 10)
            return res;
        unordered_set<int> myset;
        unordered_map<char, int> m;
        m['A'] = 0;
        m['C'] = 1;
        m['G'] = 2;
        m['T'] = 3;
        
        int hash = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (i < 9) {
                hash = (hash << 2) + m[s[i]];
            }
            else {
                hash = (hash << 2) + m[s[i]];
                hash = hash & ( (1<< 20) - 1); //get the last 20 bits, which corresponds to a substr of size 10
                string str = s.substr(i-9, 10);
                if (myset.find(hash) != myset.end() && find(res.begin(), res.end(), str) == res.end()) {
                    res.push_back(str);
                }
                else {
                    myset.insert(hash);
                }
            }
        }
        return res;
    }
    
    //naive solution, just for practice, using unordered_set, surprisingly, AC
    vector<string> findRepeatedDnaSequences_navie(string s) {
        vector<string> res;
        if (s.length() < 10)
            return res;
        unordered_set<string> myset;
        for (int i = 0; i <= s.length() - 10; i ++) {
            string str = s.substr(i, 10);
            if (myset.find(str) != myset.end() && std::find(res.begin(), res.end(), str) == res.end()) {
                res.push_back(str);
            }
            else {
                myset.insert(str);
            }
        }
        return res;
    }
};
