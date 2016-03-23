
class Solution {
public:
    //ref: https://leetcode.com/discuss/72756/solution-in-c-using-deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty())
            return res;
        queue<int> win;
        deque<int> max_q;//hold maximal value in a window
        for (int i = 0; i < nums.size(); i ++) {
            win.push(nums[i]);
            while (!max_q.empty() && nums[i] > max_q.back()) {//4, 4, 3, 2, k = 3
                //1, 2, 2, 3, 4, 4, k = 3
                max_q.pop_back();
            }
            max_q.push_back(nums[i]);
            
            if (win.size() == k) {//k >= 1
                int t = win.front();//
                win.pop();
                res.push_back(max_q.front());
                if (t == max_q.front())
                    max_q.pop_front();
            }
        }
        return res;
    }
};
