
class Solution {
public:
    void backtracking(vector<char> & chars, string & path, vector<bool>&used, vector<string> & res) {
        if (path.size() == chars.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < chars.size(); i ++) {
            if (used[i])
                continue;
            if (i > 0 && chars[i] == chars[i-1] && used[i-1])//the way to avoid duplicated solution
                continue;
            path.push_back(chars[i]);
            used[i] = true;
            backtracking(chars, path, used, res);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;//char and the number of times it appears
        for (auto c : s) {
            m[c] ++;
        }
        vector<char> chars;
        int odd_cnt = 0;
        char odd_char;
        for (auto p : m) {
            if (p.second % 2 == 1) {
                odd_cnt ++;
                if (odd_cnt > 1)
                    return res;//no valid solution
                odd_char = p.first;
            }
            for (int j = 0; j < p.second/2; j ++)
                chars.push_back(p.first);
        }
        sort(chars.begin(), chars.end());
        vector<string> half;
        string path;
        vector<bool> used(chars.size(), false);
        for (auto c : chars)
            cout << c << " ";
        cout << endl;
        backtracking(chars, path, used, half);
        
        for (auto x : half) {
            string tmp = x;
            reverse(tmp.begin(), tmp.end());
            if (odd_cnt == 1) {
                res.push_back(x+odd_char+tmp);
            }
            else {
                res.push_back(x+tmp);
            }
        }
        return res;
    }
};
