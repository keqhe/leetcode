
class Solution {
public:
    //ref: https://github.com/keqhe/leetcode/blob/master/round2/leetcode9.cpp
    //idea: based on calculation
    bool isPalindrome(int x) {
        if (x < 0)   
            return false;
        int sum = 0;
        int target = x;
        while (x > 0) {
            sum = sum*10 + x % 10;
            x /= 10;
        }
        
        return sum == target;
    }
};
