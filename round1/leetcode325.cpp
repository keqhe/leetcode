
class Solution {
public:
    //https://leetcode.com/discuss/77873/o-n-c-solution-using-unordered_map
    
    int maxSubArrayLen(vector<int>& nums, int k) {
        int currSum = 0;
        int maxRange = 0;
        unordered_map<int, int> m;//sum, range
        
        for (int i = 0; i < nums.size(); i ++) {
            currSum += nums[i];
            if (currSum == k)
                maxRange = i + 1;
            if (m.find(currSum) == m.end())
                m[currSum] = i;
            if (m.find(currSum-k) != m.end()) {//m[currSum-k] = j; m[currSum] = i; range is i - j?
                maxRange = max(maxRange, i - m[currSum-k]) ;      
            }
        }
        
        return maxRange;
    }
};
