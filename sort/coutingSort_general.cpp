#include<iostream>
#include<string>
#include<vector>

using namespace std;

//time complexity is O(n+k), where n is the array size and k is the number range
void countingSort(vector<int>& nums) {
	if (nums.empty())
		return;
	int start = nums[0], end = nums[0];
	for (auto x : nums) {
		if (start > x)
			start = x;
		if (end < x)
			end = x;
	}
	int range = end-start+1;
	vector<int> counts(range, 0);
	for (int i = 0; i < nums.size(); i ++) {
		counts[nums[i]-start] ++;
	}
	for (int i = 1; i < range; i ++) {
		counts[i] = counts[i] + counts[i-1];
	}
	cout << "debug" << endl;
	vector<int> B(nums.size(), 0);
	//backward to make sorting stable
	for (int i = nums.size()-1; i >= 0; i --) {
		int val = nums[i];
		int pos = --counts[val-start];
		B[pos] = val;
	}
	nums = B;
}

void printVector(vector<int> & nums) {
	for (auto x : nums)
		cout << x << " ";
	cout << endl;
}
int main() {
	vector<int> nums = {1001, 1002, 1001, 503, 209, 1200};
	printVector(nums);
	countingSort(nums);
	printVector(nums);
	return 0;
}
