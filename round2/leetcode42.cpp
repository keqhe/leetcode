
class Solution {
public:
    //two pointer, see https://leetcode.com/discuss/10046/share-my-short-solution
    //at index i, the area of water is determined by the max height on its left (including itself) and max height on its right (including itself)
    int trap(vector<int>& height) {
        int leftMax = 0;
        int rightMax = 0;
        int a = 0;
        int b = height.size() - 1;
        int sum = 0;
        while (a < b) {//
            leftMax = max(leftMax, height[a]);
            rightMax = max(rightMax, height[b]);
            if (leftMax < rightMax) {
                sum += (leftMax - height[a]);
                a ++;//looking for a potential larger leftMax
            }
            else {
                sum += rightMax - height[b];
                b --;
            }
        }
        return sum;
    }
    //the stack solution can be found here
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-trapping-rain-water.html
};
