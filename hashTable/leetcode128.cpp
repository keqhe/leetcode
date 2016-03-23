
class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> se;
        for (auto x: nums)
            se.insert(x);
        int maxLen = 1;
        for (int i = 0; i < nums.size(); i ++) {
            int curr = nums[i];
            if (se.find(curr-1) == se.end()) {
                int tmp = curr;
                int j = 0;
                while (se.find(tmp) != se.end()) {
                    tmp ++;
                    j ++;
                }
                maxLen = max(j, maxLen);
            }
        }
        return maxLen;
    }
    /*
    class Solution {
    public:
    //idea: use "unordered_set" (hash)
    //ref: http://www.geeksforgeeks.org/longest-consecutive-subsequence/
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set <int> us;
        for (auto & x: nums)
            us.insert(x);
        int res = 0;
        for (auto & x: nums) {
            if (us.find(x-1) == us.end()) {//the first element of a sequence
                int tmp = x;
                while (us.find(tmp) != us.end()) {
                    us.erase(tmp);
                    tmp ++;
                }
                res = max(res, tmp - x);
            }
        }
        
        return res;
    }
};
    */
};
