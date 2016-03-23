
class Solution {
public:
    bool isPrime(int x) {
        for (int i = 2; i <= sqrt(x); i ++) {//prime number is > 1, natural numer
            if (x % i == 0)
                return false;
        }
        return true;
    }
    int countPrimes2(int n) {
        int total = 0;
        for (int i = 2; i < n; i ++) {
            total += isPrime(i);
        }
        return total;
    }
    
    int countPrimes(int n) {
        bool *arr = new bool[n];
        int count = 0;
        for (int i = 2; i < n; i ++) {//prime number is natural number > 1
            arr[i] = true; //is prime true
        }
        for (int i = 2; i * i < n; i ++) {
            for (int j = i*i; j < n; j = j + i) {
                arr[j] = false;
            }
        }
        
        for (int i = 2; i < n; i ++) {
            if (arr[i])
                count ++;
        }
        return count;
    }
};
