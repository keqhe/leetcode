
class Solution {
public:
    //99*99 = 9801
    //81 162 81
    //1  0  8  9
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return "";
        int len1 = num1.length();
        int len2 = num2.length();
        
        vector<long> tmp(len1+len2, 0);//1000*1000 = 1000000, 99*99 < 9801
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < len1; i ++) {
            for (int j = 0; j < len2; j ++) {
                tmp[i+j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        int carry = 0;
        string res;
        for (int i = 0; i < len1+len2; i ++) {
            int curr = tmp[i] + carry;
            int digit = curr % 10;
            carry = curr / 10;
            res.push_back(digit+'0');
        }
        
        while (res.size() > 1) {
            if (res.back() == '0')
                res.pop_back();
            else
                break;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
