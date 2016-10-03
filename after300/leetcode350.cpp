
class Solution {
public:
    //https://discuss.leetcode.com/topic/45893/c-hash-table-solution-and-sort-two-pointers-solution-with-time-and-space-complexity
    
    //if data is not too large
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> m;
        for (auto x : nums1)
            m[x] ++;
        for (auto x : nums2) {
            if (m.find(x) != m.end() && m[x] > 0) {
                --m[x];
                res.push_back(x);
            }
        }
        return res;
    }
    //sorting large dataset - mapreduce, merge sort, bucket sort
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++ i;
                ++ j;
            }
            else if (nums1[i] < nums2[j]) {
                ++ i;
            }
            else {
                ++j;
            }
        }
        return res;
    }
};
