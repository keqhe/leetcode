
class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0)
            return false;
        unordered_set<long> happened;
        happened.insert(n);
        while (true) {
            int sum = 0;
            while (n > 0) {
                int a = n % 10;
                sum += a*a;
                n /= 10;
            }
            if (sum == 1)
                return true;
            if (happened.find(sum) != happened.end())
                return false;
            else
                happened.insert(sum);
            n = sum;
        }
    }
};
