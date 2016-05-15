
class Solution {
public:
    //naive solution, using the following isPrime, time complexity is O(n*sqrt(n))
    bool isPrime(int x) {
        for (int i = 2; i*i <= x; i ++)
            if (x % i == 0)
                return true;
        return false;
    }
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        vector<bool> Primes(n, true);// note, all prime numbers are greater than 1, 1 is not considered prime number
        Primes[0] = false;
        Primes[1] = false;
        for (int i = 2; i*i < n; i ++) {
            for (int j = i*i; j < n; j += i)
                Primes[j] = false;
        }
        int cnt = 0;
        for (auto x : Primes)
            if (x)
                cnt ++;
        return cnt;
    }
};
