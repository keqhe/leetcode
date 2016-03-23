
class Solution {
public:
    vector<int> helper1(string s, int left, int right) {
        bool pureNum=true;
        vector<int> res;
        for (int i = left; i <= right; i ++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                pureNum = false;
                vector<int> lefts = helper1(s, left, i - 1);
                vector<int> rights = helper1(s, i+1, right);
                for (int l: lefts) {
                    for (int r: rights) {
                        if (s[i] == '+') res.push_back(l+r);
                        else if (s[i] == '-') res.push_back(l-r);
                        else if (s[i] == '*') res.push_back(l*r);
                    }
                }
            }
        }
        if (res.empty()) {
            string str = s.substr(left, right-left+1);
            res.push_back(stoi(str));
        }
        return res;
    }
    vector<int> helper2(string s) {
        bool pureNum = true;
        vector<int> res;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {//think about 1+2-3
                pureNum = false;
                string l = s.substr(0, i);
                string r = s.substr(i+1);
                vector<int> lefts = helper2(l);
                vector<int> rights = helper2(r);
                for (int a: lefts) {
                    for (int b: rights) {
                        switch (s[i]) {
                            case '+' : res.push_back(a+b); break;
                            case '-' : res.push_back(a-b); break;
                            case '*' : res.push_back(a*b); break;
                        }
                    }
                }
            }
        }
        if (pureNum) {
                res.push_back(stoi(s));
        }
        return res;
    }
    //use hashmap to remember already computed results
    vector<int> helper3(string s, unordered_map<string, vector<int>> & m) {
        if (m.find(s) != m.end()) {
            return m[s];
        }
        bool pureNum = true;
        vector<int> res;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {//think about 1+2-3
                pureNum = false;
                string l = s.substr(0, i);
                string r = s.substr(i+1);
                vector<int> lefts = helper2(l);
                vector<int> rights = helper2(r);
                for (int a: lefts) {
                    for (int b: rights) {
                        switch (s[i]) {
                            case '+' : res.push_back(a+b); break;
                            case '-' : res.push_back(a-b); break;
                            case '*' : res.push_back(a*b); break;
                        }
                    }
                }
            }
        }
        if (pureNum) {
                res.push_back(stoi(s));
        }
        //
        m[s] = res;
        return res;
    }
    
    //ref:https://leetcode.com/discuss/61617/clean-c-solution-with-explanation
    vector<int> helper(string& input, int startIdx, int endIdx) {
        vector<int> result;
        for (int i = startIdx; i <= endIdx; i++) {
            if (input[i] =='+'|| input[i] == '-' || input[i] == '*') {
                vector<int> left = helper(input, startIdx, i-1);
                vector<int> right = helper(input, i+1, endIdx);
                for (int val1 : left) {
                    for (int val2 : right) {
                        switch(input[i]) {
                            case '+': result.push_back(val1 + val2); break;
                            case '-': result.push_back(val1 - val2); break;
                            case '*': result.push_back(val1 * val2); break;
                        }
                    }
                }
            }
        }
        if (result.empty()){
            int operand = 0;
            int i = startIdx;
            operand = stoi(input.substr(startIdx, endIdx-startIdx+1));
            /*
            while(i < input.size() && isdigit(input[i])) {
                operand = 10 * operand + (input[i]-'0');
                i++;
            }*/
            result.push_back(operand);
        }
        return result;
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.length() == 0)
            return res;
        unordered_map<string, vector<int>> m;
        //return helper1(input, 0, input.length()-1);
        //return helper2(input);
        return helper3(input, m);
    }
};
