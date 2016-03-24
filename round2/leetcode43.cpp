
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int size1 = num1.length();
        int size2 = num2.length();
        vector<int> tmp(size1+size2, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < size1; i ++) {
            for (int j = 0; j < size2; j ++) {
                tmp[i+j] += (num1[i] - '0')*(num2[j] - '0');
            }
        }
        int carry = 0;
        for (int i = 0; i < tmp.size(); i ++) {
            int sum = (tmp[i] + carry);
            tmp[i] = sum % 10;
            carry = sum / 10;
        }
        for (int i = 0; i < tmp.size(); i ++) {
            res += tmp[i] + '0';
        }
        //while (!res.empty() && res.back() == '0') {
        while (res.length() > 1 && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
