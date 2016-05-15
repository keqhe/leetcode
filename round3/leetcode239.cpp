
class Solution {
public:
    //the first idea is to check every possible window and example what the largest element in each window, (so the time complexity is O(nk))
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty())
            return res;
        if (k == 1)
            return nums;
        deque<int> de;
        queue<int> win;
        for (int i = 0; i < nums.size(); i ++) {//take [0, 2, 1, 5] and k = 2 as an example
            win.push(nums[i]);
            while (!de.empty() && nums[i] > de.back()) {
                de.pop_back();
            }
            de.push_back(nums[i]);
            if(win.size() == k) {//get a window
                int currMax = de.front();
                int moveOut = win.front();
                win.pop();
                if (moveOut == currMax)
                    de.pop_front();
                res.push_back(currMax);
            }
        }
        return res;
    }
};
