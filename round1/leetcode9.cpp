
class Solution {
public:
    bool isPalindrome(int x) {
        string sint;
        int left, right;
        
        if (x < 0)
            return false;
        sint = to_string(x);
        left = 0;
        right = sint.size() -1;
        while (left <= right) {
            if (sint[left] == sint[right]) {
                left ++;
                right --;
            }
            else
                return false;
        }
        return true;
    }
};
