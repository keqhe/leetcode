
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        int a = 1;
        for (int i = 0; i <= 31; i ++) {
            if ( (a << i) == n)
                return true;
        }
        return false;
    }
};
