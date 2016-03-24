
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty())
            return 0;
        int a = 0;
        int b = height.size() - 1;
        int maxArea = 0;
        int leftMax = 0;
        int rightMax = 0;
        while (a < b) {
            leftMax = max(leftMax, height[a]);
            rightMax = max(rightMax, height[b]);
            if (leftMax < rightMax) {
                int area = leftMax*(b-a);
                maxArea = max(maxArea, area);
                a ++;
            }
            else {
                int area = rightMax*(b-a);
                maxArea = max(maxArea, area);
                b --;
            }
        }
        return maxArea;
    }
};
