
class Solution {
public:
    //multimap to act as a binary search tree
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || nums.size() <= 1)
            return false;
        multimap<int, int> m;
        for (int i = 0; i < nums.size(); i ++)
            m.insert(make_pair(nums[i], i));//sort based on the first element
        auto p = m.begin();
        while (p != m.end()) {
            auto p1 = p;
            advance(p1, 1);
            while (p1 != m.end() && (long)p1->first - (long)p->first <= t) {
                if (abs(p1->second - p->second) <= k)
                    return true;
                advance(p1, 1);//advance modifies p1
            }
            advance(p, 1);//advance modifies p, while next does not
        }
        return false;
    }
};
