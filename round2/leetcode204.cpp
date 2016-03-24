
class Solution {
public:
    bool isPrime(int n) {
        for (int i = 2; i*i <= n; i ++) {
            if ( n % i == 0)
                return false;
        }
        return true;
    }
    //prime number is greater than 1!!!!!
    int countPrimes_naive(int n) {
        int c = 0;
        for (int i = 2; i < n; i ++) {
            if (isPrime(i))
                c++;
        }
        return c;
    }
    //based on the mark idea
    int countPrimes(int n) {
        vector<bool> mark (n+1, true);
        for (int i = 2; i*i < n; i ++) {
            for (int j = i*i; j < n; j += i) {
                mark[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i ++) {
            if (mark[i])
                count ++;
        }
        return count;
    }
};
