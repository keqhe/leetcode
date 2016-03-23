
class Solution {
public:
    //idea: stack or two points
    //ref: https://leetcode.com/discuss/68470/stack-following-approach-similar-largest-rectangle-histogram
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;
        int total_water = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i ++) {
            if (st.empty() || height[st.top()] >= height[i])
                st.push(i);
            else {
                int last = st.top();
                st.pop();
                if (!st.empty()) {
                    int last_before_last = st.top();
                    int area = (min(height[i], height[last_before_last]) - height[last]) * (i - last_before_last - 1);
                    total_water += area;
                }
                i --;
            }
        }
        return total_water;
    }
};
