
class Solution {
public:
    int reverse(int x) {
        string tmp = to_string(x);
        int sign = 1;
        if (tmp.front() == '+') {
            sign = 1;
            tmp = tmp.substr(1);
        }
        else if (tmp.front() == '-') {
            sign = -1;
            tmp = tmp.substr(1);
        }
        std::reverse(tmp.begin(), tmp.end());
        while (tmp.length() > 1 && tmp.front() == '0') {
            tmp = tmp.substr(1);
        }
        long res = stol(tmp);
        if (sign == 1 & res > numeric_limits<int>::max())
            return 0;
        else if (sign == -1 && res == 2147483647L)
            return numeric_limits<int>::min();
        else if (sign == -1 && res > numeric_limits<int>::max())
            return 0;
        return sign*(int) res;
    }
};
