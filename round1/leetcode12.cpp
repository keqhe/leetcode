
class Solution {
public:
    //e.g., 9 = IX, 621 = DCXXI
    string intToRoman(int num) {
        unordered_map<int, char> m;
        vector<string> noman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> numbers =  {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string s;
        while (num > 0) {
            for (int i = 0; i < numbers.size(); i ++) {
                if (num >= numbers[i]) {
                    num -= numbers[i];
                    s += noman[i];
                    break;
                }
            }
        }
        
        return s;
    }
};
