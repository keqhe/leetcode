
class Solution {
public:
    bool canWinNim_TLE(int n) {
        if (n <= 3)
            return true;
        else {
            return (!canWinNim(n-1) || !canWinNim(n-2) || !canWinNim(n-3));
        }
    }
    bool canWinNim(int n) {
        return n % 4;
    }
};
