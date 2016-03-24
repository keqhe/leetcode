
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        string res;
        vector<string> tmp1 = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> tmp2 = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        while (num > 0) {
            for (int i = 0; i < tmp2.size(); i ++) {
                if (num >= tmp2[i]) {
                    num -= tmp2[i];
                    res += tmp1[i];
                    break;
                }
            }
        }
        return res;
    }
};
