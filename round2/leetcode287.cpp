
class Solution {
public:
    //method 1, binary search, see ref: https://leetcode.com/discuss/74367/java-easy-version-to-understand
    
    int findDuplicate(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int low = 1;
        int high = nums.size() - 1;//i.e., n in this question
        int possible=1;//think why this trick does not work in this case, this trick works only when an explict == exists
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (auto x : nums) {
                if (x <= mid)
                    count ++;
            }
            if (count > mid) {
                possible = mid;
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;//think why returning low is okay
    }
    //this O(1) space complexity and O(n) time complexity is interestingg
    //method 2: Tortoise & Haire cycle detection algorithm
    //see ref: https://leetcode.com/discuss/62696/tortoise-%26-haire-cycle-detection-algorithm
    
};
