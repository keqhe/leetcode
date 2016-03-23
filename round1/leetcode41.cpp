
class Solution {
public:
    //in a real interview, first consider using hash table or unordered_set (hash set)
    int __firstMissingPositive(vector<int>& nums) {
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); i ++) {
            us.insert(nums[i]);
        }
        int k;
        for (k = 1; k <= nums.size(); k ++) {// <= not <
            if (us.find(k) == us.end())
                return k;
        }
        
        return nums.size() + 1;
    }
    
    //https://leetcode.com/discuss/60525/100%25-fast-elegant-java-index-based-solution-with-explanation
    //a good question: https://leetcode.com/discuss/59396/regarding-first-missing-positive-what-if-nums-1-3-5-7
    //c++ cleaner version: https://leetcode.com/discuss/53480/accepted-4ms-c-solution-with-std-swap
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n;) {
            //nums is (0, n]
            //if nums[i] does not appear at position nums[i] - 1
            if (nums[i] > 0 && nums[i] <=n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
            else 
                i ++;
        }
        for (int i = 0; i < n; i ++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        //reaching the end
        return n + 1;
    }
};
