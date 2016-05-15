
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int i=0;
        string res;
        while (i < min(a.length(), b.length())) {
            int now = a[i] - '0' + b[i] -'0' + carry;
            res.push_back('0'+(now%2));
            carry = now/2;
            i ++;
        }
        while (i < a.length()) {
            int now = a[i] - '0' + carry;
            res.push_back('0'+(now%2));
            carry = now/2;
            i ++;
        }
        while (i < b.length()) {
            int now = b[i] - '0' + carry;
            res.push_back('0'+(now%2));
            carry = now/2;
            i ++;
        }
        if (carry)
            res.push_back('0'+1);
        reverse(res.begin(), res.end());
        return res;
    }
};
