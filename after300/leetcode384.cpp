
class Solution {
public:
    //https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
    vector<int> orginal;
    Solution(vector<int> nums) {
        orginal = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orginal;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> tmp = orginal;
        for (int i = tmp.size()-1; i >= 0; --i) {
            int j = random() % (i+1);
            swap(tmp[i], tmp[j]);
        }
        return tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
