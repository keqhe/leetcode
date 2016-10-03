
class Solution {
public:
    //hash table, key is the sum from 0 to curr index, value is current index
    //if (m.find(k-nums[i]) != m.end()), max_len = max(max_len, i-m[k-nums[i]])
    int maxSubArrayLen(vector<int>& nums, int k) {
        long acc = 0;
        unordered_map<long, int> m;
        int max_len = 0;
        for (int i = 0; i < nums.size(); i ++) {
            acc += nums[i];
            if (acc == k) {
                max_len = i + 1;
            }
            else {
                long other = acc - k;
                if (m.find(other) != m.end()) {
                    max_len = max(max_len, i-m[other]);
                }
            }
            if (m.find(acc) == m.end()) {
                m[acc] = i;
            }
        }
        return max_len;
    }
};
