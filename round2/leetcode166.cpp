
class Solution {
public:
    //https://leetcode.com/discuss/50512/accepted-clean-java-solution
    //how to do division?
    string fractionToDecimal(int numerator, int denominator) {
        bool sign = false;//false means plus
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            sign = true;//true means minus
        cout << "sign is :" << sign << endl;
        long num = abs((long)numerator);
        long den = abs((long)denominator);
        string res;
        long shang = num / den;
        res += to_string(shang);
        num = num % den;
        if (num != 0)
            res.push_back('.');
        
        unordered_map<long, int> m; //first corresponds to BEI CHU SHU, second responds to index
        int index = res.length();
        while (num != 0) {
            num *= 10;
            shang = num / den;
            if (m.find(num) == m.end()) {
                m[num] = index;
                index ++;
                res += to_string(shang);
            }
            else {
                int starting = m[num];
                res.insert(res.begin()+starting,'(');
                res.push_back(')');
                break;
            }
            num = num % den;
        }
        if (sign)
                res.insert(res.begin(), '-');
        return res;
    }
};
