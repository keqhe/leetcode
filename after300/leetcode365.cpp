
class Solution {
public:
    int gcd(int x, int y) {
        if (y == 0)
            return x;
        else {
            return gcd(y, x % y);
        }
    }
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0)
            return true;
        return ((z <= x+y) && (z % gcd(x, y) == 0));
    }
};
