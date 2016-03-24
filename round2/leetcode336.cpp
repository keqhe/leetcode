
class Solution {
public:
    //the naive solution faces TLE
    bool isPal(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left ++;
            right --;
        }
        return true;
    }
    //time complexity, O(NK^2)
    //ref: https://leetcode.com/discuss/91226/o-nk-2-c-ac-solution-320ms
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        if (words.empty())
            return res;
        unordered_map<string,int> m;
        unordered_set<string> se;
        for (int i = 0; i < words.size(); i ++)
            m[words[i]] = i;
        vector<int> tmp(2);
        for (int i = 0; i < words.size(); i ++) {
            string curr = words[i];
            string prefix = curr;
            string suffix = curr;
            int K = curr.length();
            for (int len = 0; len <= K; len ++) {
                if (isPal(prefix, 0, len-1)) {
                    string rest = prefix.substr(len);
                    reverse(rest.begin(), rest.end());
                    if (m.find(rest) != m.end()) {
                        tmp[0] = m[rest];
                        tmp[1] = i;
                        string key = to_string(tmp[0]) + "-"+ to_string(tmp[1]);
                        if (tmp[0] != tmp[1] && se.find(key) == se.end()) {
                            res.push_back(tmp);
                            se.insert(key);
                        }
                    }
                }
                if (isPal(suffix, len, K-1)) {
                    string rest = suffix.substr(0, len);
                    reverse(rest.begin(), rest.end());
                    if  (m.find(rest) != m.end()) {
                        tmp[1] = m[rest];
                        tmp[0] = i;
                        string key = to_string(tmp[0]) + "-"+ to_string(tmp[1]);
                        if (tmp[0] != tmp[1] && se.find(key) == se.end()) {
                            res.push_back(tmp);
                            se.insert(key);
                        }
                    }
                }
            }
        }
        
        return res;
    }
};
