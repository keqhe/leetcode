
class Solution {
public:
    int myAtoi(string str) {
        //handle spaces
        while (!str.empty()) {
            if (str.front() == ' ')
                str.erase(str.begin());
            else
                break;
        }
        //handle signs
        int sign = 1;//means positive or zero
        if (!str.empty() && !isdigit(str.front())) {
            if (str.front() == '-') {
                sign = -1;
                str.erase(str.begin());
            }
            else if (str.front() == '+') {
                str.erase(str.begin());
            }
        }
        if (str.empty() || !isdigit(str.front()))
            return 0;
        string tmp;
        for (int i = 0; i < str.length(); i ++) {
            if (isdigit(str[i]))
                tmp.push_back(str[i]);
            else    
                break;
        }
        //delete heading zeros
        while (!tmp.empty()) {
            if (tmp.front() == '0')
                tmp.erase(tmp.begin()) ;
            else
                break;
        }
        long sum = 0;
        while (!tmp.empty()) {
            char c = tmp.front();
            sum = sum*10 + c - '0';
            tmp.erase(tmp.begin());
            if (sign*sum > numeric_limits<int>::max())
                return numeric_limits<int>::max();
            if (sign*sum < numeric_limits<int>::min())
                return numeric_limits<int>::min();
        }
        return sign*sum;
    }
};
