
class Solution {
public:
    //refer:https://leetcode.com/discuss/50512/accepted-clean-java-solution
    //hash table and string operation and math
    string fractionToDecimal(int numerator, int denominator) {
        int sign = 1;
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) {
            sign = -1;
        }
        cout << "sign is " << sign << endl;
        cout << "-2147483648 < 0 " << (-2147483648 < 0) << endl;
        long numeratorL = abs((long) numerator);
        long denominatorL = abs((long) denominator);
        
        string res;
        map<long, int> index;
        long quo = numeratorL / denominatorL;
        res += to_string(quo);
        numeratorL = numeratorL % denominatorL;
        if (numeratorL == 0) {
            if (sign == 1)
                return res;
            else if (sign == -1)
                return "-" + res;
        }
        
        res += '.';
        int j = res.length()-1;
        while (numeratorL != 0) {
            numeratorL *= 10;
            quo = numeratorL / denominatorL;
            if (index.find(numeratorL) == index.end()) {
                j ++;
                index[numeratorL] = j;
                res += to_string(quo);
            }
            else {//repeated numeratorL
                int firstAppear = index[numeratorL];
                res.insert(firstAppear, 1, '(');
                res.push_back(')');
                break;
            }
            numeratorL = numeratorL % denominatorL;
        }
        if (sign == 1)
            return res;
        else if (sign == -1)
            return "-"+res;
    }
};
