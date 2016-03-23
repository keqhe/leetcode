
class Solution {
public:
    //reference: http://www.programcreek.com/2013/02/leetcode-3sum-closest-java/
    int threeSumClosest(vector<int>& nums, int target) {
        int Min = numeric_limits<int>::max();
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i< nums.size(); i ++) {
            int curr = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int now = curr + nums[left] + nums[right];
                if (abs(now - target) < Min) {
                    Min = abs(now - target);
                    res = now;
                }
                
                if (now == target)
                    return target;
                else if (now < target) {
                    left ++;
                }
                else 
                    right --;
            }
        }
        
        return res;
    }
};
