
class Solution {
public:
    bool isPrime(int num) {
            bool prime_yes = true;
            for (int i = 2; i < num/2; i ++) {
                if (num % i == 0)
                    prime_yes = false;
            }
            return prime_yes;
    }
        
    bool isUgly(int num) {
        if (num == 1)
                return true;
        if (num < 1)
                return false;
        while (num % 2 == 0)
                num /= 2;
        while (num % 3 == 0)
                num /= 3;
        while (num % 5 == 0)
                num /= 5;
        return num == 1;    
    }
};
