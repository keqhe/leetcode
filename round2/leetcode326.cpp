
class Solution {
public:
    //https://leetcode.com/discuss/78532/summary-all-solutions-new-method-included-at-15-30pm-jan-8th
    //iterative version
    bool isPowerOfThree_idea1(int n) {
        if (n > 1) {
            while (n % 3 == 0) n /= 3;
        }   
        return n == 1;
    }
    //math
    //3^x = n, log10(3^x) = log10(n) --> x = log10(n) / log10(3)
    bool isPowerOfThree(int n) {
        if (n < 1)
            return false;
        double d = log10(n) / log10(3);
        if (ceil(d) == floor(d))
            return true;
        else
            return false;
    }
};
