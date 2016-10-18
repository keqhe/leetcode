
class Solution {
public:
    //bucket sort, http://www.geeksforgeeks.org/bucket-sort-2/
    //time complexity is O(n) and memory cost is O(n), where n is the number of elements in the array
    void sortColors_bucket(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int size = nums.size();
        int min_val = numeric_limits<int>::max();
        int max_val = numeric_limits<int>::min();
        
        for (auto x : nums) {
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }
        max_val ++;
        vector<vector<int>> buckets(size, vector<int>());
        for (auto x : nums) {
            int index = (float)(x - min_val) / (max_val - min_val) * size;
            buckets[index].push_back(x);
        }
        for (auto& v : buckets) {
            sort(v.begin(), v.end());
        }
        nums.clear();
        for (const auto& v : buckets) {
            for (auto x : v) {
                nums.push_back(x);
            }
        }
    }
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int max_val = numeric_limits<int>::min();
        int min_val = numeric_limits<int>::max();
        
        for (auto x : nums) {
            max_val = max(max_val, x);
            min_val = min(min_val, x);
        }
        int size = max_val - min_val + 1;
        vector<int> counts(size, 0);
        
        for (auto x : nums) {
            counts[x-min_val] ++;
        }
        for (int i = 1; i < counts.size(); i ++) {
            counts[i] += counts[i-1];
        }
        
        vector<int> B(nums.size(), 0);
        for (int i = B.size()-1; i >= 0; i --) {
            int val = nums[i];
            int index = --counts[val-min_val];
            B[index] = val;
        }
        nums = B;
    }
};
