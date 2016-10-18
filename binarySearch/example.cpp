#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int l = 0;
	int r = nums.size()-1;
	int target = -1;
	while (l <= r) {
		int mid = l + (r-l) / 2;
		cout << "l and r : " << l << " " << r << endl;
		if (nums[mid] == target) {
			cout << "found" << endl;
			break;
		}
		else if (nums[mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << "l and r : " << l << " " << r << endl;
	return 0;
}
