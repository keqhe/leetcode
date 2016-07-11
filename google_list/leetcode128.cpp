
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> us;
        int max_len = 0;
        for (auto x : nums)
            us.insert(x);
        for (auto x : nums) {
            if (us.find(x-1) == us.end()) {
                int curr_len = 0;
                while (us.find(x) != us.end()) {
                    curr_len ++;
                    x ++;
                }
                max_len = max(max_len, curr_len);
            }   
        }
        return max_len;
    }
};
