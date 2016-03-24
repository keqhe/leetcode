
class Solution {
public:
    
    string getPermutation(int n, int k) {
        int base;
        vector<int> fact (n+1, 1);
        for (int i = 2; i < n+1; i ++) {
            fact[i] = fact[i-1]*i;
        }
        vector<int> res(n,0);
        vector<int> candidates(n, 0);
        for (int i = 0; i < n; i ++) 
            candidates[i] = i+1;
        k --;
        for (int i = n-1; i >= 0; i--) {
            int base = fact[i];
            int index = k / base;
            k = k % base;
            res[n-1-i] = candidates[index];
            candidates.erase(candidates.begin()+index);
        }
        string tmp;
        for (int i = 0; i < n; i ++)
            tmp += to_string(res[i]);
        return tmp;
    }
};
