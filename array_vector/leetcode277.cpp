
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    //ref: https://leetcode.com/discuss/83845/java-easy-version-to-understand
    //ref: https://leetcode.com/discuss/56413/java-solution-two-pass
    int findCelebrity(int n) {
        
        bool r;
        int candidate = 0;
        int i;
        for (i = 1; i < n; i ++) {
            if (knows(candidate, i)) //Exclusion way to find candiate
                candidate = i;
        }
        
        //check whether the candidate is a real celebrity
        for (i = 0; i < n; i ++) {
            if (i == candidate || knows(i, candidate) && !knows(candidate,i))
                continue;
            else
                break;
        }
        if (i == n)
            return candidate;
        else
            return -1;
    }
};
