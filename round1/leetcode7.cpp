
class Solution {
public:
    int reverse(int x) {
        int pos;
        unsigned long long int acc = 0;
        
        if (x < 0)
            pos = -x;
        else
            pos = x;
        while (pos > 0) {
            acc *= 10;
            acc += pos % 10;
            pos /= 10;
            if (acc > numeric_limits<int>::max())
                return 0;
        }
        if (x < 0)
            return -acc;
        else
            return acc;
        
    }
};
