
class Solution {
public:
    bool exists(string s) {//leetcode 266
        unordered_set<char> se;
        for (auto x : s) {
            if (se.find(x) == se.end())
                se.insert(x);
            else
                se.erase(x);
        }
        return se.empty() || se.size() == 1;
    }
    void backtracking(vector<char> & perm, string &path, vector<bool> &used, vector<string> & res, string mid) {
        if (path.length() == perm.size()) {
            string tmp = path;
            reverse(tmp.begin(), tmp.end());
            res.push_back(path+mid+tmp);
            return;
        }
        
        for (int i = 0; i < perm.size(); i ++) {
            if (used[i])
                continue;
            if (i > 0 && perm[i] == perm[i-1] && used[i-1])
                continue;
            path.push_back(perm[i]);
            used[i] = true;
            backtracking(perm, path, used, res, mid);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        if (!exists(s))
            return res;
        unordered_map<char, int> m;
        for (auto c : s) {
            m[c] ++;
        }
        vector<char> perm;
        string mid_point;
        for (auto p : m) {
            if (p.second % 2 == 1)
                mid_point = string(1, p.first);
            for (int i = 0; i < p.second/2; i ++)
                    perm.push_back(p.first);
        }
        string path;
        vector<bool> used (perm.size(), false);
        backtracking(perm,path, used, res, mid_point);
        
        return res;
    }
};
