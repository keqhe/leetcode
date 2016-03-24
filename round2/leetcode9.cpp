
class Solution {
public:
    //based on calculation
    //ref: https://leetcode.com/discuss/83851/6-lines-straightforward-c-solution
    //example: 191
    bool isPalindrome(int x) {
        int sum = 0;
        int target = x;
        while (x > 0) {
            //sum += sum * 10 + x % 10; WRONG
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        cout << sum << endl;
        return (sum == target);
    }
};
