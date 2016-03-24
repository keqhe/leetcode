
class Solution {
public:
    //ref: https://leetcode.com/discuss/60011/c-28ms-solution-using-multimap
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        multimap<long, int> mm;
        for (int i = 0; i < nums.size(); i ++)
            mm.insert(make_pair(nums[i], i));
        multimap<long, int>::iterator p1 = mm.begin();
        while (p1 != mm.end()) {
            auto p2 = p1;
            advance(p2, 1);
            while (p2 != mm.end() && p2->first - p1->first <= t) {
                if (abs(p2->second - p1->second) <= k)
                    return true;
                p2 ++;
            }
            p1++;
        }
        return false;
    }
};
