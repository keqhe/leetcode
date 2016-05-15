
class Solution {
public:
    //0! = 1
    //total cnt = floor(n/5) + floor(n/25) + floor(n/125)...
    int trailingZeroes(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += n/5;
            n /= 5;
        }
        return cnt;
    }
};
