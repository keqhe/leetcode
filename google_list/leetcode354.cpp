
bool myCmp(const pair<int, int> & p1, const pair<int, int> & p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    else
        return p1.second > p2.second;
}
int LIS(vector<int> & nums) {
    if (nums.empty())
        return 0;
    int size = nums.size();
    //dp[i] denotes the LIS ending at nums[i];
    vector<int> dp(size, 1);
    int maxLen = 1;
    for (int i = 1; i < size; i ++) {
        for (int j = 0; j < i; j ++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty())
            return 0;
        sort(envelopes.begin(), envelopes.end(), myCmp);
        vector<int> nums;
        for (auto e : envelopes) {
            nums.push_back(e.second);
        }
        return LIS(nums);
    }
};
