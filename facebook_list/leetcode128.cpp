
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (auto x : nums)
            us.insert(x);
        int max_len = 0;
        for (auto x : nums) {
            int local = 0;
            if (us.find(x-1) == us.end()) {
                while (us.find(x) != us.end()) {
                    local ++;
                    x ++;
                }
                max_len = max(max_len, local);
            }
        }
        return max_len;
    }
};
