
class Solution {
public:
    //majority voting can be extended to [n/3] case, there are 2 candidates, at most
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1;
        int candidate2;
        int count1 = 0;
        int count2 = 0;
        for (auto n : nums) {
            if (count1 != 0 && n == candidate1) {
                count1 ++;
                continue;
            }
            if (count2 != 0 && n == candidate2) {
                count2 ++;
                continue;
            }
            if (count1 == 0) {
                candidate1 = n;
                count1 = 1;
                continue;
            }
            if (count2 == 0) {
                candidate2 = n;
                count2 = 1;
                continue;
            }
            
            count1 --;
            count2 --;
        }
        int sum1 = 0;
        int sum2 = 0;
        for (auto n : nums) {
            if (n == candidate1) {
                sum1 ++;
            }
            else if (n == candidate2) {
                sum2 ++;
            }
        }
        vector<int> res;
        if (sum1 > nums.size()/3)
            res.push_back(candidate1);
        if (sum2 > nums.size()/3)
            res.push_back(candidate2);
        return res;
    }
};
