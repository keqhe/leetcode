
class Solution {
public:
    //permutation (be careful about duplicates)
    void backtracking(string s, string &path, vector<bool>& used, vector<string> & res) {
        if (path.length() == s.length()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < s.length(); i ++) {
            if (used[i])
                continue;
            if (i > 0 && s[i] == s[i-1] && used[i-1])
                continue;
            used[i] = true;
            path.push_back(s[i]);
            backtracking(s, path, used, res);
            used[i] = false;
            path.pop_back();
        }
    }
    
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        for (auto c : s) {
            m[c] ++;
        }
        int odd_number = 0;
        char odd_char;
        for (auto kv : m) {
            if (kv.second % 2 != 0) {
                odd_number ++;
                odd_char = kv.first;
                if (odd_number > 1)
                    return res;
            }
        }
        string half;
        for (auto kv : m) {
                half += string(kv.second/2, kv.first);
        }
        sort(half.begin(), half.end());
        cout << "half is :" << half << endl;
        vector<bool> used(half.size(), false);
        vector<string> halves;
        string path;
        backtracking(half, path, used, halves);
        for (auto x : halves) {
            cout << "x is : " <<x << endl;
            string y = x;
            reverse(y.begin(), y.end());
            if (odd_number == 1) {
                res.push_back(x+odd_char+y);
            }
            else {
                res.push_back(x+y);
            }
        }
        return res;
    }
};
