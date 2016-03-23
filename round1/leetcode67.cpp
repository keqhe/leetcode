
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length();
        int n = b.length();
        int carry = 0;
        int total = max(m, n);
        string temp, ret;
        int i = m - 1;
        int j = n - 1;
        while (total) {
            int parta, partb;
            if (i >= 0) {
               parta = a[i] - '0'; //char to int
               i --;
            }
            else
                parta = 0;
            if (j >= 0) {
                partb = b[j] - '0';
                j --;
            }
            else
                partb = 0;
            carry += parta + partb;
            if (carry == 0 || carry == 1) {
                temp += to_string(carry);
                carry = 0;
            }
            else if (carry == 2 || carry == 3) { // forgot this initially
                temp += to_string(carry % 2);
                carry = 1;
            }
            total --;
        }
        if (carry) {
            temp += '1';
        }
        for (int i = temp.length() - 1; i >= 0; i --) {
            ret += temp[i];
        }
        return ret;
    }
};
