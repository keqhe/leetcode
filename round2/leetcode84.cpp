
class Solution {
public:
    //naive, TLE
    int largestRectangleArea_naive(vector<int>& heights) {
        if (heights.empty())
            return 0;
        int len = heights.size();
        int maxArea = 0;
        int i, j;
        for (i = 0; i < len; i ++) {
            int minHeight = numeric_limits<int>::max();
            for (j = i; j < len; j ++) {
                minHeight = min(minHeight, heights[j]);
            }
            //cout << "debug" << minHeight << endl;
            maxArea = max(maxArea, minHeight * (j-i+1));
        }
        return maxArea;
    }
    //O(nlogn) solution using divide and conquer, but still TLE
    //see ref: https://leetcode.com/discuss/84911/geeks-for-geeks-thought-on-how-to-solve-the-problem
    /*The idea is to find the minimum value in the given array.
    Once we have index of the minimum value, the max area is maximum of following three values.
    a) Maximum area in left side of minimum value (Not including the min value)
    b) Maximum area in right side of minimum value (Not including the min value)
    c) Number of bars multiplied by minimum value.
    */
    int helper(vector<int>& heights, int left, int right) {
        if (left > right)
            return 0;
        long minHeight = numeric_limits<long>::max();
        int minIndex = -1;
        for (int i = left; i <= right; i ++) {
            if (heights[i] < minHeight) {
                minHeight = heights[i];
                minIndex = i;
            }
        }
        
        return max(max(helper(heights,left,minIndex-1), helper(heights,minIndex+1,right)), 
                (right-left+1)*(int)minHeight);
    }
    int largestRectangleArea_NlogN(vector<int>& heights) {
        if (heights.empty())
            return 0;
        return helper(heights, 0, heights.size()-1);
    }
    
    //O(n) solution, ref: https://leetcode.com/discuss/84911/geeks-for-geeks-thought-on-how-to-solve-the-problem
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        stack<int> st;//store indexes, and the heights (with the index values in the stack) are non-decreasing
        int i = 0;
        int maxArea = 0;
        while (i < heights.size()) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i);
                i ++;
            }
            else {//heights[st.top()] > heights[i]
                int tp = st.top();
                st.pop();
                //we know the height[i] > height[tp] and 
                //height[st.top()] <= height[tp] (if st is not empty()
                int h = heights[tp];
                
                int curr = h*(st.empty() ? i : i-1-st.top());//example: [1,3,2], tp == 2, and height[tp] = 3
                maxArea = max(maxArea, curr);
            }
        }
        
        while (!st.empty()) {//bars of increasing heights, think about [1,2,3,4] as input
            int tp = st.top();
            st.pop();
            //we know the height[i] > height[tp] and 
            //height[st.top()] <= height[tp] (if st is not empty()
            int h = heights[tp]; 
                
            int curr = h*(st.empty() ? i : i-1-st.top());//example: [1,3,2], tp == 2, and height[tp] = 3
            maxArea = max(maxArea, curr);
        }
        
        return maxArea;
    }
};
