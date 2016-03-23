
class Solution {
public:
    //first solution
    /*
    bool isPowerOfThree(int n) {
        while (n > 1) {
            n /= 3;
        }
        return n == 1;
    }
    */
    //ref: https://leetcode.com/discuss/78657/c-accepted-solution
    bool isPowerOfThree(int n) {
        if (n == 0)
            return false;
        string tmp = to_string(n);
        if (tmp.length() >= 1 && (tmp.back() == '0' || tmp.back() == '2' || tmp.back() == '4' || tmp.back() == '5' || tmp.back() == '6' || tmp.back() == '8'))
            return false;
        float left = log(n) / log(3);
        cout << left << endl;
        cout << ceil(left) << endl;
        cout << floor(left) << endl;
        return ceil(left) == floor(left) ? true : false;
    }
};
