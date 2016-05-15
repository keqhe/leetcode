
class Solution {
public:
    //TLE but correct
    bool canWinNim_TLE(int n) {
        if (n <= 3)
            return true;
        return (!canWinNim(n-1) || !canWinNim(n-2) || !canWinNim(n-3));
    }
    //n = 1, 2, 3, win
    //n = 4, lose
    //n = 4*1 + 1, 2, 3, win;
    //n = 4*2, lose
    bool canWinNim(int n) {
        return n % 4;
    }
};
