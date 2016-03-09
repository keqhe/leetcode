#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //[1,3,1,1,1]
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (left == right)
                return nums[left];
            int mid = left + (right - left)/2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else 
                right --;
        }
    }
};
int main() {
	class Solution sn;
	return 0;
}
