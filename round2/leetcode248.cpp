
class Solution {
public:
    //the first thought is to get all strings first and then check how many satisfy the condition, this will cause MLE
    //here is a very good ref: https://leetcode.com/discuss/61245/c-ac-and-clean-any-ideas-to-make-it-faster
    bool mycmp(string s1, string s2) {
        if (s1.length() != s2.length())
            return s1.length() < s2.length() ? true : false;
        else 
            return s1 < s2;
    }
    void helper(string low, string high, int & count, string sol) {
        if (mycmp(high, sol))
            return;//sol is large enough (not valid), no need to add more chars
        //if (mycmp(low, sol) && mycmp(sol, high)) {
        
        if (!mycmp(sol, low) && !mycmp(high, sol)) {
            if (sol.length() == 1 || (sol.length() > 1 && sol[0] != '0'))
                count ++;
        }
        helper(low, high, count, '0'+sol+'0');
        helper(low, high, count, '1'+sol+'1');
        helper(low, high, count, '8'+sol+'8');
        helper(low, high, count, '6'+sol+'9');
        helper(low, high, count, '9'+sol+'6');
    }
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        helper(low, high, count, "");
        helper(low, high, count, "1");
        helper(low, high, count, "0");
        helper(low, high, count, "8");
        return count;
    }
};
