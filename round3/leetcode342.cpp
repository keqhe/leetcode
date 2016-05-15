
class Solution {
public:
    //0101 = 5
    //0001
    //10000 = 16
    //1
    bool isPowerOfFour(int num) {
        long a = 1;
        for (int i = 1; i < 31; i ++) {
            if (a > numeric_limits<int>::max())
                return false;
            if (a == num)
                return true;
            a *= 4;
            cout << a << endl;
        }
        return false;
    }
};
