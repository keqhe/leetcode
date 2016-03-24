
class Solution {
public:
    //0 1 
    //10 11
    //100 101 110 111
    //1000 1001 1010 1011 1100 1101 1110 1111
    //10000 10001 10010 10011 10100 10101 10110 10111 11000 
    //ref: https://leetcode.com/discuss/92609/three-line-java-solution
    //tmp[i] = tmp[i/2] + i & 1;
    vector<int> countBits(int num) {
        vector<int> tmp(num+1, 0);
        for (int i = 1; i <= num; i ++) {
            //tmp[i] = tmp[i >> 1] + i & 1; //note this is WRONG!
            tmp[i] = tmp[i >> 1] + (i & 1);
        }
        return tmp;
    }
};
