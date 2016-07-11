
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i = 0; i < digits.size(); i ++) {
            int curr = carry + digits[i];
            res.push_back(curr % 10);
            carry = curr / 10;
        }
        if (carry)
            res.push_back(1);
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
