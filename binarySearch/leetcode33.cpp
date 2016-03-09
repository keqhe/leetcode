#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //the clean ref: https://leetcode.com/discuss/41134/java-ac-solution-using-once-binary-search
    //when a sorted array is rotated, at least one half is still ordered
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[left] <= nums[mid]) {//[left..mid] is ordered
                if (target < nums[mid] && nums[left] <= target) //target is in range [left, mid-1]
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if (nums[mid] <= nums[right]) {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;//if not found
    }
};

int main() {
	class Solution sn;
	return 0;
}
