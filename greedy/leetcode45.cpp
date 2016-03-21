
class Solution {
public:
    //ref: https://leetcode.com/discuss/78360/java-easy-version-to-understand-o%EF%BC%88n%EF%BC%89
    int jump(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 0;
        int step = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i+nums[i] >= nums.size()-1) {
                step ++;
                return step;
            }
            //for all the j's that i can reach, which j can reach the most far away
            int Max = -1;
            int pos = i+1;
            for (int j = i+1; j <= i+nums[i]; j ++) {
                if (j-i+nums[j] > Max) {
                    Max = j-i+nums[j];
                    pos = j;
                }
            }
            i = pos - 1;//think why, because i ++
            step ++;
        }
    }
};
