
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i --) {
            carry += digits[i];
            if (carry <= 9) {
                digits[i] = carry;
                carry = 0;
            }
            else if (carry == 10) {
                digits[i] = 0;
                carry = 1;
            }
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
            
        return digits;
    }
};
