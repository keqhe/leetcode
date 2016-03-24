
class Solution {
public:
    //the first thought is hash table, but there is a algorithm to handle this problem
    //https://en.wikipedia.org/wiki/Boyer–Moore_majority_vote_algorithm
    //O(n) and O(1) space
    int majorityElement(vector<int>& nums) {
        int candidate;
        int counter = 0;
        for (auto n : nums) {
            if (counter == 0) {
                candidate = n;
                counter = 1;
            }
            else if (candidate == n) {
                counter ++;
            }
            else {
                counter --;
            }
        }
        
        int frequence = 0;
        for (auto n : nums) {
            if (candidate == n)
                frequence ++;
        }
        if (frequence >= nums.size() / 2) {
            return candidate;
        }
        else
            return -1;
    }
};
