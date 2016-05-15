
class Solution {
public:
    bool backtracking(string s, long curr_sum, long last) {
        string curr = to_string(curr_sum);
        if (curr == s) {
            return true;
        }
        if (curr.length() < s.length()) {
            int len = curr.length();
            string num_str = s.substr(0, len);
            if (stoi(num_str) == curr_sum) {
                if (backtracking(s.substr(len), last+stoi(num_str), stoi(num_str)))
                    return true;
            }
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        if (num.length() < 3)
            return false;
        for (int i = 0; i < num.length()-2; i ++) {//"123"
            for (int j = i+1; j < num.length()-1; j ++) {
                string num1 = num.substr(0, i+1);
                string num2 = num.substr(i+1, j-(i+1)+1);
                if (num1.length() > 1 && num1.front() == '0' ||
                    num2.length() > 1 && num2.front() == '0')
                        continue;
                cout << "check: " << num1 << " " << num2 << endl;
                long curr_sum = stol(num1) + stol(num2);
                long last = stol(num2);
                if (backtracking(num.substr(j+1), curr_sum, last))
                    return true;
            }
        }
        return false;
    }
};
