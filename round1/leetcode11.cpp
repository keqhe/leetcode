
class Solution {
public:
    //volume = min(ai, aj)*(j-i), i < j
    //when height[i] < height[j], i ++ so we can possibly find a larger volume. If we fix i, then for any value k < j, we will get a smaller volume
    //when hright[i] >= height[j], i -- so we can possible find a larger volume. If we fix j, then for any value i < k < j, we will get a smaller volume
    int maxArea(vector<int>& height) {
        if (height.size() < 2)
            return 0;
        int mx = 0;
        
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            mx = max(mx, min(height[i], height[j])*(j-i));
            if (height[i] < height[j])
                i ++;
            else
                j --;
        }
        return mx;
    }
};
