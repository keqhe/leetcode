
class Solution {
public:
    int myAtoi(string str) {
        //remove leading spaces
        while (!str.empty()) {
            if (str.front() == ' ')
                str = str.substr(1);
            else
                break;
        }
        //cout << str.size() << endl;
        //if str is not valid
        if (str.empty() || (str.front() > '9' || str.front() < '0') && (str.front() != '+' && str.front() != '-')) {
            cout << "str is not valid.." << endl;
            return 0;
        }
        //exam sign
        int sign = 1;
        if (str.front() == '+') {
            sign = 1;
            str = str.substr(1);
        }
        else if (str.front() == '-') {
            sign = -1;
            str = str.substr(1);
        }
        cout << "debug1..." << endl;
        //take care of tailing non-digit chars
        int i;
        for (i = 0; i < str.length(); i ++) {
            if (str[i] > '9' || str[i] < '0')
                break;
        }
        //like case: str = "123&"
        str = str.substr(0, i);
        cout << "debug..." << endl;
        //well, this is such a test case: "9223372036854775809"
        
        long res = 0;
        for (i = 0; i < str.length(); i ++) {
            res = res*10 + str[i] - '0';
            if (sign == 1 && res > numeric_limits<int>::max())
                return numeric_limits<int>::max();//2147483647
            else if (sign == -1 && res > numeric_limits<int>::max())
                return numeric_limits<int>::min();//-2147483648
        }
        if (sign == 1 && res > numeric_limits<int>::max())
            return numeric_limits<int>::max();//2147483647
        else if (sign == -1 && res > numeric_limits<int>::max())
            return numeric_limits<int>::min();//-2147483648
        return sign*res;
    }
};
