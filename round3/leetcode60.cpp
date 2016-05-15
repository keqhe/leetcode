
class Solution {
public:
    //there is a math method
    string getPermutation(int n, int k) {
        string res;
        vector<int> factor(n+1, 1);
        for (int i = 2; i <= n; i ++)
            factor[i] = factor[i-1]*i;//1 1 2 6 
        vector<int> candidates(n, 0);
        for (int i = 0; i < n; i ++)
            candidates[i] = i + 1;
        vector<int> tmp(n, 0);
        k --;//think about k = 5
        for (int i = n-1; i >= 0; i --) {
            int base = factor[i];
            int index = k / base;
            k = k % base;
            tmp[n-1-i] = candidates[index];
            candidates.erase(candidates.begin()+index);
        }
        for (auto x: tmp)
            res += x + '0';
        return res;
    }
    //we can also use backtracking, we looks like we have TLE problem
    void backtracking(int &cnt, int n, int k, string & path, vector<bool>&used, string & res) {
        if (cnt > k)
            return;
        if (path.length() == n) {
            cnt ++;
            if (cnt == k)
                res = path;
            return;
        }
        for (int i = 1; i <= n; i ++) {
            if (!used[i]) {
                path.push_back(i+'0');
                used[i] = true;
                backtracking(cnt, n, k, path, used, res);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    string getPermutation_TLE(int n, int k) {
        string res;
        if (n == 0)
            return res;
        int cnt = 0;
        vector<bool> used(n+1, false);
        string path;
        backtracking(cnt, n, k, path, used, res);
        return res;
    }
};
