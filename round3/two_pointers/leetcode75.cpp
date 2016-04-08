
class Solution {
public:
    //counting sort
    void sortColors(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return;
        int minVal = numeric_limits<int>::max();
        int maxVal = numeric_limits<int>::min();
        for (auto x : nums) {
            minVal = min(minVal, x);
            maxVal = max(maxVal, x);
        }
        vector<int> counts(maxVal-minVal+1, 0);
        for (auto x : nums) {
            //counts[x] ++; //WRONG, think why
            counts[x-minVal] ++;
        }
        
        for (int i = 1; i < counts.size(); i ++) {
            counts[i] = counts[i] + counts[i-1];
        }
        
        vector<int> B(nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; i --) {
            int val = nums[i];
            //int pos = --counts[val];//WRONG, think why
            int pos = --counts[val-minVal];//index starting from 0
            B[pos] = val;
        }
        nums = B;
    }
};
