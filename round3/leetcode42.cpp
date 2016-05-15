
class Solution {
public:
    //idea: two pointer
    //at index i, the the area of water it can contribute is max(leftHeight, rightHeight) - currHeight
    int trap(vector<int>& height) {
        int LH = 0;
        int RH = 0;
        int left = 0;
        int right = height.size()-1;
        int areaSum = 0;
        while (left <= right) {
            LH = max(LH, height[left]);
            RH = max(RH, height[right]);
            if (LH <= RH) {
                areaSum += LH - height[left];
                left ++;
            }
            else {
                areaSum += RH - height[right];
                right --;
            }
        }
        return areaSum;
    }
};
