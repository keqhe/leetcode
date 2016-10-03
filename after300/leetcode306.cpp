
class Solution {
public:
    bool backtracking(string str1, string str2, string left) {
        if (left.empty())
            return true;
        long num1 = stol(str1);
        long num2 = stol(str2);
        long number = num1 + num2;
        string str_number = to_string(number);
        string str3 = left;
        if (str3.length() > 1 && str3.front() == '0')
            return false;
        string next = str3.substr(0, str_number.length());
        if (str3.length() >= str_number.length() && next == str_number) {
            left = str3.substr(str_number.length());
            if (backtracking(str2, next, left))
                return true;
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        for (int i = 0; i+3 <= num.length(); i ++) {
            for (int j = i+1; j+2 <= num.length(); j ++) {
                string str1 = num.substr(0, i+1);
                string str2 = num.substr(i+1, j-i);
                if (str1.length() > 1 && str1.front() == '0')
                    continue;
                if (str2.length() > 1 && str2.front() == '0')
                    continue;
                long num1 = stol(str1);
                long num2 = stol(str2);
                long number = num1 + num2;
                string str_number = to_string(number);
                string str3 = num.substr(j+1);
                if (str3.length() > 1 && str3.front() == '0')
                    continue;
                if (str3.length() >= str_number.length() && str3.substr(0, str_number.length()) == str_number) {
                    cout << str1 << " " << str2 << " " << str3 << endl;
                    if (backtracking(str1, str2, str3))
                        return true;
                }
            }
        }
        return false;
    }
};
