
class Solution {
public:
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-substring-with-concatenation.html
    //
    bool checkValid(int start, unordered_map<string,int> & m, int wordLen, int totalWords, string & s) {
        unordered_map<string, int> tmp;
        
        for (int i = start; i <= start + wordLen*totalWords - wordLen; i += wordLen) {
            string str = s.substr(i, wordLen);
            if (m.find(str) == m.end()) 
                return false;
            tmp[str] ++;
            if (tmp[str] > m[str])
                return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty())
            return res;
        unordered_map<string, int> m;
        for (auto & x: words)
            m[x] ++;
        int wordLen = words[0].length();
        int totalWords = words.size();
        int strLen = wordLen*totalWords;
        cout << "strLen :" << strLen << endl;
        
        //for (int i = 0; i <= s.length() - strLen; i ++) {//this is WRONG!
        for (int i = 0; i + strLen <= s.length(); i ++) {
            cout << "i is ..." << i << endl;
            cout << (int)s.length() - strLen << endl;
            if (checkValid(i, m, wordLen, totalWords, s))
                res.push_back(i);
        }
        
        return res;
    }
};
