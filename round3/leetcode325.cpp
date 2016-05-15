
class Solution {
public:
    //O(n) solution: https://github.com/keqhe/leetcode/blob/master/round2/leetcode325.cpp
    //using hash table to record the accumulated sum till index i. m[acc] = i, where acc is the sum from
    //nums[0] to nums[i]
    //[1,2,3] and k = 5, m[1] = 0, m[6] = 2, m[6-k] = m[1] 
    //it is in the hash table, so maxLen = max(maxLen, i-0)
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long, int> m; //key is the accumulated sum from index 0 to i, value is i
        long acc = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i ++) {
            acc += nums[i];
            if (acc == k) {
                maxLen = max(maxLen, i + 1);
            }
            else {
                long b = acc - k;
                if (m.find(b) != m.end()) {
                    maxLen = max(maxLen, i-m[b]);
                }
            }
            
            if (m.find(acc) == m.end())
                m[acc] = i;
        }
        return maxLen;
    }
    
    //there is a naive arroach which has O(n^2) time complexity and O(1) space
};
