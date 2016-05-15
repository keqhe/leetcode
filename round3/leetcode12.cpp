
class Solution {
public:
    //Roman numerical system: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1,000.
    string intToRoman(int num) {
        vector<int> t1 =    {1000, 900, 500, 400,  100,  90,  50,  40,   10,   9,    5,   4,    1};
        vector<string> t2 = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res;
        while (num > 0) {
            for (int i = 0; i < t1.size(); i ++) {
                if (t1[i] <= num) {
                    num -= t1[i];
                    res += t2[i];
                    break;
                }
            }
        }
        return res;
    }
};
