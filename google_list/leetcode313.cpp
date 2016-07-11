
class Solution {
public:
    //check Ugly Number II
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0 || primes.empty())
            return 0;
        vector<int> uglynumbers(n, 0);
        uglynumbers[0] = 1;
        vector<int> index(primes.size(), 0);
        for (int i = 1; i < n; i ++) {
            int curr_min = uglynumbers[index[0]]*primes[0];
            for (int j = 1; j < primes.size(); j ++) {
                curr_min = min(curr_min, uglynumbers[index[j]]*primes[j]);
            }
            uglynumbers[i] = curr_min;
            
            for (int j = 0; j < primes.size(); j ++) {
                if (curr_min == uglynumbers[index[j]]*primes[j])
                    index[j] ++;
            }
        }
        return uglynumbers[n-1];
    }
};
