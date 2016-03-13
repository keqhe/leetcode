#include<vector>
#include<iostream>

using namespace std;

//quick sort, see http://www.geeksquiz.com/quick-sort/

int partition(vector<int> & nums, int left, int right) {
	int i = left - 1;
	int j;
	int pivot = nums[right];
	for (j = left; j <= right - 1; j ++) {
		if (nums[j] <= pivot) {
			i ++;
			swap(nums[j], nums[i]); 
		}
	}
	swap(nums[i+1], nums[right]);
	return i+1;
}

void quickSort(vector<int> & nums, int left, int right) {
	if (left < right) {
		int mid = partition(nums, left, right);
		quickSort(nums, left, mid-1);
		quickSort(nums, mid+1, right);		
	}
}
void printVector(vector<int> & nums) {
	for (auto x : nums)
		cout << x << " ";
	cout << endl;	
}

int main() {
	vector<int> nums = {1,3,0, 9, 2, 7, 4};
	printVector(nums);
	quickSort(nums, 0, nums.size()-1);
	printVector(nums);
	return 0;
}
