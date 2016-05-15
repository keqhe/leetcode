
class Solution {
public:
    vector<int> helper(string s, int l, int r) {
        vector<int> res;
        bool flag = false;
        for (int i = l; i <= r; i ++) {
            if (s[i] == '+') {
                flag = true;
                vector<int> a = helper(s, l, i-1);
                vector<int> b = helper(s, i+1, r);
                for (auto x : a) {
                    for (auto y : b) {
                        res.push_back(x+y);
                    }
                }
            }
            else if (s[i] == '-') {
                flag = true;
                vector<int> a = helper(s, l, i-1);
                vector<int> b = helper(s, i+1, r);
                for (auto x : a) {
                    for (auto y : b) {
                        res.push_back(x-y);
                    }
                }
            }
            else if (s[i] == '*') {
                flag = true;
                vector<int> a = helper(s, l, i-1);
                vector<int> b = helper(s, i+1, r);
                for (auto x : a) {
                    for (auto y : b) {
                        res.push_back(x*y);
                    }
                }
            }
        }
        if (flag == false) {
            int tmp = stoi(s.substr(l, r-l+1));
            res.push_back(tmp);
            return res;
        }
        else {
            return res;
        }
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.empty())
            return res;
        return helper(input, 0, input.length()-1);
    }
};
