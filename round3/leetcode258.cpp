
class Solution {
public:
    int addDigits_naive(int num) {
        while (num/10 > 0) {
            int tmp = 0;
            while (num / 10 > 0) {
                tmp += num % 10;
                num /= 10;
            }
            num += tmp;
        }
        return num;
    }
    //digital root of n is 1+(n-1)%9
    int addDigits(int num) {
        if (num == 0)
            return 0;
        return 1+(num-1)%9;
    }
};
