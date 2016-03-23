
class Solution {
public:
    //why not unordered_set? test case: "aaaaaa"
    void backtracking(string & s, string & curr, vector<bool> & used, unordered_set<string> & res) {
        if (s.length() == curr.length()) {
            res.insert(curr);
            return;
        }
        for (int i = 0; i < s.length(); i ++) {
            if (used[i])
                continue;
            used[i] = true;
            curr.push_back(s[i]);
            backtracking(s, curr, used, res);
            used[i] = false;
            curr.pop_back();
        }
    }
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        if (s.empty()) {
            res.push_back("");
            return res;
        }
        unordered_map<char, int> m;
        
        for (auto & c : s) {
            m[c] ++;
        }
        
        int odd_number = 0;
        char odd_char;
        string half;
        for (auto & x: m) {
            int count = x.second;
            if (count % 2 == 0) {
                for (int i = 0; i < count/2; i ++) {
                    half.push_back(x.first);
                }
            }
            else {
                odd_number ++;
                odd_char = x.first;
                for (int i = 0; i < count/2; i ++) {
                    half.push_back(x.first);
                }
                if (odd_number > 1)
                    return res;//does not have a solution
            }
        }
        cout << half << endl;
        vector<bool> used (half.length(), false);
        unordered_set<string> allStr;
        string curr;
        //backtracking(half, "", used, allStr); This is WRONG if using a reference for string
        backtracking(half, curr, used, allStr);
        for (auto & s : allStr) {
            string tmp = s;
            string t;
            t += tmp;
            if (odd_number == 1)
                t += odd_char;
            reverse(tmp.begin(), tmp.end());
            t += tmp;
            res.push_back(t);
        }
        
        return res;
    }
};
