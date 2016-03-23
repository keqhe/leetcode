
class Solution {
public:
    //40!
    // 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15 * 16 * 17 * 18 * 19 * 20
    // * 21 * 22 * 23 
    // 40 / 5 = 8
    // 40 / 10 = 4
    // 40 
    //count = floor(n/5) + floor(n/25) + floor(n/125)
    int trailingZeroes(int n) {
        int total5 = 0;
        for (long i = 5; i <= n; i = i*5) {//here you can expect interger overflow
            total5 += n/i;
        }
        return total5;
    }
};
