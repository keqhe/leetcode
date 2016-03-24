
class Solution {
public:
    //TLE, the first thought
    int maxSubArrayLen_naive(vector<int>& nums, int k) {
        int maxLen = 0;
        for (int len = 1; len <= nums.size(); len ++) {
            for (int i = 0; i + len <= nums.size(); i ++) {
                int sum = 0;
                for (int j = i; j < i + len; j ++) {
                    sum += nums[j];
                }
                if (sum == k) {
                    maxLen = max(len, maxLen);
                }
            }
        }
        return maxLen;
    }
    //using hashtable to record the the acc sum till nums[i]
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long, int> m;
        int maxLen = 0;
        long sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int x = nums[i];
            sum += x;
            if (sum == k) {
                maxLen = max(maxLen, i + 1);//start from 0
            }
            else {
                long b = sum - k;
                if (m.find(b) != m.end()) {
                    maxLen = max(maxLen, i - m[b]);
                }
            }
            
            if (m.find(sum) == m.end())
                m[sum] = i;
        }
        return maxLen;
    }
};
