
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    //explain: The first loop is to find the candidate as the author explains. In detail, suppose the candidate after the first for loop is person k, it means 0 to k-1 cannot be the celebrity, because they know a previous or current candidate. Also, since k knows no one between k+1 and n-1, k+1 to n-1 can not be the celebrity either. Therefore, k is the only possible celebrity, if there exists one.
    //ref: https://leetcode.com/discuss/56413/java-solution-two-pass
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; i ++) {
            if (knows(candidate, i))
                candidate = i;
        }
        //assuming that after this loop, candidate = k, then k does not know anyone in [k+1, n-1]
        //also, for iterms in [0, k-1], because they know previous candidate or current candidate, so
        //they must not be the celebrity
        for (int i = 0; i < n; i ++) {
            if (i != candidate && (knows(candidate,i) || !knows(i, candidate)))
                return -1;
        }
        return candidate;
    }
};
