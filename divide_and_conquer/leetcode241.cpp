class Solution {
public:
    vector<int> helper(string s, int left, int right) {
        vector<int> res;
        bool plus = false;
        bool minus = false;
        bool multi = false;
        for (int i = left; i <= right; i ++) {
            if (s[i] == '+')
                plus = true;
            else if (s[i] == '-')
                minus = true;
            else if (s[i] == '*')
                multi = true;
        }
        if (!plus && !minus && !multi) {
            int a = stoi(s.substr(left, right-left+1));
            res.push_back(a);
            return res;
        }
        for (int i = left; i <= right; i ++) {
            if (s[i] == '+') {
                vector<int> v1 = helper(s, left, i-1);
                vector<int> v2 = helper(s, i+1, right);
                for (auto x : v1) {
                    for (auto y : v2) {
                        res.push_back(x+y);
                    }
                }
            }
            else if (s[i] == '-') {
                vector<int> v1 = helper(s, left, i-1);
                vector<int> v2 = helper(s, i+1, right);
                for (auto x : v1) {
                    for (auto y : v2) {
                        res.push_back(x-y);
                    }
                }
            }
            else if (s[i] == '*') {
                vector<int> v1 = helper(s, left, i-1);
                vector<int> v2 = helper(s, i+1, right);
                for (auto x : v1) {
                    for (auto y : v2) {
                        res.push_back(x*y);
                    }
                }
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.empty())
            return res;
        return helper(input, 0, input.length()-1);
    }
};
