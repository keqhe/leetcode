
class Solution {
public:
    //the following version is a bit hard to understand
    int maxArea__(vector<int>& height) {
        if (height.empty() || height.size() == 1)
            return 0;
        int maxArea = 0;
        int l = 0;
        int r = height.size()-1;
        while (l < r) {
            maxArea = max(maxArea, min(height[l], height[r])*(r-l));
            if (height[l] <= height[r])
                l ++;
            else
                r --;
        }
        return maxArea;
    }
    int maxArea(vector<int>& height) {
        if (height.empty() || height.size() == 1)
            return 0;
        int maxArea = 0;
        int maxL = 0;//at the index i, the max height of range [0..i]
        int maxR = 0;//at the index j, the max height of range [j...size-1]
        int l = 0;
        int r = height.size()-1;
        while (l < r) {
            maxL = max(maxL, height[l]);
            maxR = max(maxR, height[r]);
            if (maxL <= maxR) {
                int area = maxL*(r-l);
                maxArea = max(maxArea, area);
                l ++;//explore a possible higher left edge
            }
            else {
                int area = maxR*(r-l);
                maxArea = max(maxArea, area);
                r --;//explore a possible higher right edge
            }
        }
        return maxArea;
    }
};
