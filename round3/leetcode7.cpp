
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        int flag = 1;//1 means positive number or 0
        if (x < 0)
            flag = -1;
        long trans = abs((long)x);
        while (trans > 0) {
            int curr = trans % 10;
            res = res*10 + curr;
            trans /= 10;
            if (res > numeric_limits<int>::max())
                return 0;
            if ((0-res) < numeric_limits<int>::min())
                return 0;
        }
        if (flag == 1)
            return res;
        else
            return -res;
    }
};
