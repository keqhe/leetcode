
// Forward declaration of the knows API.
bool knows(int a, int b);

//The idea is to use two pointers, one from start and one from the end. Assume the start person is A, and the end person is B. If A knows B, then A must not be the celebrity. Else, B must not be the celebrity. We will find a celebrity candidate at the end of the loop. Go through each person again and check whether this is the celebrity. Below is C++ implementation.
class Solution {
public:
    int findCelebrity(int n) {
        if (n == 0)
            return -1;
        int celebrity  = 0;
        for (int i = 1; i < n; i ++) {
            if (knows(celebrity, i)) {
                celebrity = i;
            }
        }
        for (int i = 0; i < n; i ++) {
            if (i == celebrity)
                continue;
            if (knows(celebrity, i))
                return -1;
            if (!knows(i, celebrity))
                return -1;
        }
        return celebrity;
    }
};
