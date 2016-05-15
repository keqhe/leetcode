
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long a = 1;
        for (int i = 0; i <= 31; i ++) {
            if ((a << i) == n)
                return true;
        }
        return false;
    }
};
