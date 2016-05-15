
class Solution {
public:
    //https://github.com/keqhe/leetcode/blob/master/round2/leetcode229.cpp
    //at most there are 2 majority elements
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())
            return res;
        int candidate1, candidate2;
        int count1 = 0;
        int count2 = 0;
        for (auto x : nums) {
            if (count1 != 0 && candidate1 == x) {
                count1 ++;
                continue;
            }
            if (count2 != 0 && candidate2 == x) {
                count2 ++;
                continue;
            }
            if (count1 == 0) {
                candidate1 = x;
                count1 = 1;
                continue;
            }
            if (count2 == 0) {
                candidate2 = x;
                count2 = 1;
                continue;
            }
            count1 --;
            count2 --;
        }
        
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto x : nums) {
            if (x == candidate1)
                cnt1 ++;
            else if (x == candidate2)
                cnt2 ++;
        }
        if (cnt1 > nums.size()/3)
            res.push_back(candidate1);
        if (cnt2 > nums.size()/3)
            res.push_back(candidate2);
        return res;
    }
};
