
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; i --) {
            int curr = carry + digits[i];
            digits[i] = curr % 10;
            carry = curr/10;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
