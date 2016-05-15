
class Solution {
public:
    //first need to think the navie solution, try all possible Rectangles
    int largestRectangleArea_naive(vector<int>& heights) {
        if (heights.empty())
            return 0;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i ++) {
            int minH = numeric_limits<int>::max();
            int j = i;
            for (; j < heights.size(); j ++) {
                minH = min(heights[j], minH);
            }
            maxArea = max(maxArea, minH*(j-i+1));
        }
        return maxArea;
    }
    //the idea is shown in https://leetcode.com/discuss/84911/geeks-for-geeks-thought-on-how-to-solve-the-problem
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        stack<int> st;//it stores index
        int i = 0;
        int maxArea = 0;
        while (i < heights.size()) {
            if (st.empty() || heights[st.top()] <= heights[i]) {//st has index, those index should have increasing heights
                st.push(i);
                i ++;
            }
            else {
                int idx = st.top();
                st.pop();
                //now we know that heights[i] > heights[idx], so we want to calculate the size of the area that takes bar at index idx at the lowest bar
                int h = heights[idx];//the height of the lowest bar
                int width = st.empty() ? i : i-1-st.top();
                maxArea = max(maxArea, h*width);
            }
        }
        //for the case the bars are increasing
        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            int h = heights[idx];
            int width = st.empty() ? i : i-1-st.top();
            maxArea = max(maxArea, h*width);
        }
        return maxArea;
    }
};
