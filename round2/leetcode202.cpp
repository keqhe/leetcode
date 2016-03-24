
class Solution {
public:
    //ref: https://leetcode.com/discuss/71694/straightforward-solution
    //a straint forward solution
    int next(int n) {
        int res = 0;
        while (n > 0) {
            int tmp = n % 10;
            res += tmp*tmp;
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        if (n == 1)
            return true;
        if (n < 1)
            return false;
        unordered_set<int> us;
        while (n != 1 && us.find(n) == us.end()) {
            us.insert(n);
            n = next(n);
        }
        return n == 1;
    }
};
