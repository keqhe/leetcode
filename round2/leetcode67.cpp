
class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        int carry = 0;
        int size1 = a.length();
        int size2 = b.length();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i;
        for (i = 0; i < min(size1, size2); i ++) {
            int tmp = ((a[i] - '0') + (b[i] - '0') + carry);
            sum += (tmp % 2) + '0';
            carry = tmp / 2;
        }
        //cout << sum << endl;
        while(i < size2) {
            int tmp = (b[i] - '0') + carry;
            sum += (tmp % 2) + '0';
            carry = tmp / 2;
            i ++;
        }
        while (i < size1) {
            int tmp = (a[i] - '0') + carry;
            sum += (tmp % 2) + '0';
            carry = tmp / 2;
            i ++;
        }
        //cout << carry << endl;
        if (carry) {
            sum += '1';
        }
        //cout << sum << endl;
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
