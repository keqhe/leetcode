#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //when there is no duplicated values, when nums[left] <= nums[mid], we think range[left..mid] is in order, however, when thare no duplicated values, the assumption is not valid anymore
    //for example,
    //rotated: [1,3,1,1,1]
    //[1,1,1,1,3]
    //[3,1,1,1,1]
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
                return true;
            else if (nums[left] < nums[mid]) {
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else {//i.e., nums[mid] == nums[right] or nums[mid] == nums[left]
                if (nums[mid] == nums[left])
                    left ++;
                if (nums[mid] == nums[right])
                    right --;
            }
        }
        return false;
    }
};

int main() {
	class Solution sn;
	return 0;
}
