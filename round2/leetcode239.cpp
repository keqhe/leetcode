
class Solution {
public:
    //ref: https://leetcode.com/discuss/72756/solution-in-c-using-deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty())
            return res;
        if (k == 1)
            return nums;
        deque<int> de;
        queue<int> win;
        for (int i = 0; i < nums.size(); i ++) {
            win.push(nums[i]);
            while (!de.empty() && nums[i] > de.back()) {
                de.pop_back();
            }
            de.push_back(nums[i]);
            if (win.size() == k) {
                res.push_back(de.front());//the max the this window
                int f = win.front();
                win.pop();
                if (f == de.front()) {
                    de.pop_front();
                }
                
            }
        }
        return res;
    }
};
