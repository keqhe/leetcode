
class Solution {
public:
    //using queue is easier to understand
    //ref: https://leetcode.com/discuss/67877/%08two-standard-dp-solutions
    int nthUglyNumber(int n) {
        queue<int> q2;
        queue<int> q3;
        queue<int> q5;
        q2.push(1); q3.push(1); q5.push(1);
        int m;
        for (int i = 0; i < n; i ++) {
            m = min(q2.front(), min(q3.front(), q5.front()));
            if (m == q2.front()) 
                q2.pop();
            if (m == q3.front()) 
                q3.pop();
            if (m == q5.front()) 
                q5.pop();

            q2.push(m*2);
            q3.push(m*3);
            q5.push(m*5);
        }
        return m;
    }
    //i just want to record the wrong solution i came up with, I think this solution violates the definition of ugly number
    int nthUglyNumber_wrong(int n) {
        if (n == 1)
            return 1;
        int L2 = 2;
        int L3 = 3;
        int L5 = 5;
        int i2 = 1;
        int i3 = 1;
        int i5 = 1;
        
        int seq = 1;
        while (n > 1) {
            seq = min(L2*i2, min(L3*i3, L5*i5));
            if (seq == L2*i2)
                i2 ++;
            if (seq == L3*i3)
                i3 ++;
            if (seq == L5*i5)
                i5 ++;
            n --;
        }
        return seq;
    }
};
