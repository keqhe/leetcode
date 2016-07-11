
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign = 1;//means plus
        if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0)
            sign = -1;
        long a = abs((long)numerator);
        long b = abs((long)denominator);
        long shang = a/b;
        long yushu = a % b;
        if (yushu == 0) {
            /*if (sign*shang > numeric_limits<int>::max())
                return to_string(numeric_limits<int>::max());
            else if (sign*shang < numeric_limits<int>::min())
                return "-"+to_string(numeric_limits<int>::min());
            */
            if (sign == 1)
                return to_string(shang);
            else 
                return "-"+to_string(shang);
        }
        unordered_map<long, int> m;
        string res = to_string(shang) + '.';
        int index = res.length();
        a = yushu;
        while (a > 0) {
            a = a*10;// it is BEI CHU SHU, think why m[a]?
            if (m.find(a) != m.end()) {
                res.insert(res.begin()+m[a], '(');
                res.push_back(')');
                break;
            }
            else {
                res.push_back(a/b+'0');
                m[a] = index;
            }
            a = a % b;
            index ++;
        }
        if (sign == 1)
            return res;
        else
            return "-" + res;
    }
};
