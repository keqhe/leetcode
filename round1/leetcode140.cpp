
class Solution {
public:
    //ref1: word break I: http://www.programcreek.com/2012/12/leetcode-solution-word-break/
    //ref2: word break II: http://www.programcreek.com/2014/03/leetcode-word-break-ii-java/
    //ref3: see also: https://leetcode.com/discuss/49296/my-c-dp-dfs-solution-4ms
    
    //ref2 is CORRECT!
    
    void dfs(vector<list<string>> & dp, int index, vector<string> &curr, vector<string> & res) {
        if (index == 0) {
            if (!curr.empty()) {
                string temp;
                for (int i = curr.size() -1; i >= 0; i --) {
                    temp += ' ' + curr[i];
                }
                temp.erase(temp.begin());
                res.push_back(temp);
            }
            return;
        }
        
        list<string> l = dp[index];
        for (list<string>::iterator it = l.begin(); it != l.end(); it ++) {
                curr.push_back(*it);
                //cout << "index ..." << index << " *it " << *it << endl; 
                //cout << " index - it->length() is " << index - it->length() << endl;
                cout << endl;
                dfs(dp, index - it->length(), curr, res);
                curr.pop_back();
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<list<string>> dp (s.length()+1, list<string>());//dp[i], s[0...i-1] can form what words?
        vector<bool> dp2 (s.length()+1, false);//word break I
        vector<string> res;
        if (s.empty() || wordDict.empty())
            return res;
        
        dp2[0] = true;
        for (int i = 0; i < s.length(); i ++) {
            for (auto &w : wordDict) {
                if (!dp2[i])
                    continue;
                int end = w.length() + i;
                if (end > s.length())
                    continue;
                if (s.substr(i, w.length()) == w) {
                    dp[end].push_back(w);
                    dp2[end] = true;
                }
            }
        }
        for (list<string>::iterator it = dp[s.length()].begin(); it != dp[s.length()].end(); it ++)
            cout << *it << ' ';
        cout << endl;
        cout << dp2[s.length()] << endl;
        if (!dp2[s.length()])
            return res;
        vector<string> curr;
        dfs(dp, s.length(), curr, res);
        return res;
    }
    /* backtracking TLE*/
    /*
    void backtracking(unordered_set<string>& wordDict, string &s, int index, vector<string> & curr, vector<string> & res) {
        if (index == s.length()) {
            string temp;
            for (auto & x : curr) {
                temp += x + ' ';
            }
            temp.pop_back();//pop_back the last " "
            res.push_back(temp);
            cout << "push_back " << temp << endl;
            return;
        }
        
        for (int i = index; i < s.length(); i ++) {
            string tmp = s.substr(index, i-index+1);
            //cout << "tmp is: " << tmp << endl;
            if (wordDict.find(tmp) != wordDict.end()) {//word in "wordDict" can be used multiple times?
                //cout << "tmp is: " << tmp << endl;
                curr.push_back(tmp);
                backtracking(wordDict, s, i+1, curr, res);
                curr.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.empty() || wordDict.empty())
            return res;
        vector<string> curr;
        backtracking(wordDict, s, 0, curr, res);
        return res;
    }
    */
};
