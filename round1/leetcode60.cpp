
class Solution {
public:
    //ref:http://bangbingsyb.blogspot.com/2014/11/leetcode-permutation-sequence.html
    //example, n = 3 and k = 5;
    string getPermutation(int n, int k) {
        vector<int> factorial(n, 1);
        vector<char> nums(n, '0');
        string res;
        
        for (int i = 1; i < factorial.size(); i ++) {
            factorial[i] = factorial[i-1] * i; // note it is not "factorial[i-1]*(i+1)"
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            nums[i] += (i+1);
        }
        
        k = k - 1; //why, say n = and k = 1;
        
        for (int i = n; i >= 1; i --) {
            int j = k / factorial[i-1];
            res.push_back(nums[j]);
            k = k % factorial[i-1];
            nums.erase(nums.begin()+j);
        }
        
        return res;
    }
};
