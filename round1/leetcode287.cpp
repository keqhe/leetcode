
class Solution {
public:
    //this gril is pretty nice:http://www.hrwhisper.me/leetcode-find-the-duplicate-number/
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
            
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;//slow reset to begining
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
        
    }
};
