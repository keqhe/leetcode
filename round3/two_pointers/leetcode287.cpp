
class Solution {
public:
    //method 1, two pointers, https://leetcode.com/discuss/62696/tortoise-%26-haire-cycle-detection-algorithm
    int findDuplicate_method1(vector<int>& nums) {
        int slow = nums.size();
        int fast = nums.size();
        do {
            slow = nums[slow-1];
            fast = nums[nums[fast-1]-1];
        } while (slow != fast);
        slow = nums.size();
        while (slow != fast) {
            slow = nums[slow-1];
            fast = nums[fast-1];
        }
        return slow;
    }
    //https://en.wikipedia.org/wiki/Cycle_detection, here f function is nums[]
    //for two indexes i an j, where i != j, but nums[i] == nums[j]
    //http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];//note nums[slow] and nums[fast] must be legal, think why
            if (slow == fast)
                break;
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    //wenfei google problem
    //if you are allowed to modify the array
    //http://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
    int findDuplicate_if_you_can_modify(vector<int>& nums) {
        //1 <= nums[i] <= n, for any nums[i]
        for (int i = 0; i < nums.size(); i ++) {
            int pos = abs(nums[i])-1;
            //if nums[i] is duplicated, then nums[pos] must be negative
            if (nums[pos] > 0) {
                nums[pos] = -nums[pos];
            }
            else {
                return abs(nums[i]);
            }
        }
    }
    //the last method is binary search, please check round 2
};
