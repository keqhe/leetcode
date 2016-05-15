
class Solution {
public:
    //sorting is is trival (time complexity is O(nlogn)
    //if using counting sort or bucket sort, time complexity is O(n) but need extra space
    int firstMissingPositive_(vector<int>& nums) {
        if (nums.empty())
            return 1;
        for (int i = 0; i < nums.size(); i ++) {
            while (nums[i] > 0 && nums[i]-1 != i && nums[i] <= nums.size()) {
                if (nums[i] == nums[nums[i]-1])//consider test case [1,1]
                    break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != i+1)
                return i+1;
        }
        return nums.size()+1;//consider the test case [1]
    }
    //using unordered_set, but needs O(n) space
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty())
            return 1;
        unordered_set<int> se;
        for (auto x : nums)
            se.insert(x);
        for (int i = 1; i <= nums.size(); i ++)
            if (se.find(i) == se.end())
                return i;
        return nums.size()+1;
    }
};
