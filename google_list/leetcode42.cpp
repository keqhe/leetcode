
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2)
            return 0;
        int left = 0;
        int right = height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int sum = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                left_max = max(left_max, height[left]);
                sum += left_max - height[left];
                
                left ++;
            }
            else {
                right_max = max(right_max, height[right]);
                sum += right_max - height[right];
                right --;
            }
        }
        return sum;
    }
};
