
class Solution {
public:
    //first idea using sort (O(nlogn)), travial 
    
    int longestConsecutiveTLE(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> se;
        for (auto x : nums)
            se.insert(x);
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int currLen = 0;
            int val = nums[i];
            while (se.find(val) != se.end()) {
                currLen ++;
                val ++;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
    
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> se;
        for (auto x : nums)
            se.insert(x);
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int currLen = 0;
            int val = nums[i];
            if (se.find(val-1) == se.end()) {//avoid many unnecessary checks
                while (se.find(val) != se.end()) {
                    currLen ++;
                    val ++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};
