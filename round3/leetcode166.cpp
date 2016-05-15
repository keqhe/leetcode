
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign = 1;
        if (numerator < 0 && denominator > 0 ||
            numerator > 0 && denominator < 0)
                sign = -1;
        long a = abs((long) numerator);
        long b = abs((long) denominator);
        
        long shang = a / b;
        unordered_map<long, int> m;//chushu, and index
        string res;
        res += to_string(shang);
        long left = a % b;
        if (left > 0)
            res += '.';
        int i = res.length();//"3."
        while (left > 0) {
            left *= 10;
            shang = left / b;
            if (m.find(left) != m.end()) {
                int idx = m[left];
                res.insert(res.begin()+idx, '(');
                res.push_back(')');
                break;
            }
            else {
                res += to_string(shang);
                m[left] = i;
                i ++;//digit by digit
                
                left = left % b;
            }
        }
        if (sign == -1)
            return '-' + res;
        else
            return res;
    }
};
