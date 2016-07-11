
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty())
            return res;
        if (k == 1)
            return nums;
        queue<int> win;
        deque<int> de;
        for (int i = 0; i < nums.size(); i ++) {
            win.push(nums[i]);
            while (!de.empty() && de.back() < nums[i]) {
                de.pop_back();
            }
            de.push_back(nums[i]);
            if (win.size() == k) {
                int front = win.front();
                win.pop();
                res.push_back(de.front());
                if (front == de.front())
                    de.pop_front();
            }
        }
        return res;
    }
};
