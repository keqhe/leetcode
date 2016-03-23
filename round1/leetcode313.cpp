
class Solution {
public:
    //similar to Ugly number II, 
    //reference: https://leetcode.com/problems/ugly-number-ii/
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> index (k, 0);
        vector<int> ugly (n, numeric_limits<int>::max());
        ugly[0] = 1;
        for (int i = 1; i < n; i ++) {// "< n" is enough because ugly[0] was there
            for (int j = 0; j < k; j ++) {
                ugly[i] = min(ugly[i], primes[j]*ugly[index[j]]);
            }
            
            for (int j = 0; j < k; j ++) {
                if (ugly[i] == primes[j]*ugly[index[j]])
                    index[j] ++;
            }
        }
        return ugly[n-1];
    }
};
