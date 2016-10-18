
class Solution {
public:
    //hash table, key is the sum from 0 to curr index, value is current index
    //if (m.find(k-nums[i]) != m.end()), max_len = max(max_len, i-m[k-nums[i]])
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;
        int max_len = 0;
        int size = nums.size();
        int acc = 0;
        
        unordered_map<int, int> m;
        for (int i = 0; i < size; i ++) {
            acc += nums[i];
            if (m.find(acc) == m.end())
                m[acc] = i;
            if (acc == k) {
                max_len = max(max_len, i+1);
            }
            if (m.find(acc-k) != m.end()) {
                max_len = max(max_len, i-m[acc-k]);
            }
        }
        return max_len;
    }
};
