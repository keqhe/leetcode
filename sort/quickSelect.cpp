#include<iostream>
#include<string>
#include<vector>
#include <unistd.h>
using namespace std;

void printVector(vector<int> & nums) {
	for (int i = 0; i < nums.size(); i ++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}

void swap(int &val1, int&val2) {
	int tmp = val1;
	val1 = val2;
	val2 = tmp;
}
int partition(vector<int> & nums, int left, int right) {
	int pivot = nums[right];
	int i = left - 1;
	for (int j = left; j <= right - 1; j ++) {
		if (nums[j] <= pivot) {
			i++;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i+1], nums[right]);
	return i + 1;
}

void quickSort(vector<int> & nums, int left, int right) {
	if (left < right) {
		int index = partition(nums, left, right);
		quickSort(nums, left, index-1);
		quickSort(nums, index+1, right);
	}
}

int quickSelect(vector<int> & nums, int left, int right, int k) {
	if (left == right)
		return nums[left];
	int pivotIndex = partition(nums, left, right);
	if (k -1 == pivotIndex)
		return nums[pivotIndex];
	else if (k - 1 < pivotIndex)
		return quickSelect(nums, left, pivotIndex - 1, k);
	else
		return quickSelect(nums, pivotIndex + 1, right, k);
}
int main() {
	//vector<int> a = {6, 5, 4, 0};
	vector<int> a = {3, 2, 1, 5, 6, 4};
	cout << "before quick sort..." << endl;
	printVector(a);
	cout << "after quick sort..." << endl;
	quickSort(a, 0, a.size() - 1);
	printVector(a);
	cout << "test quickSelect..." << endl;

	a.clear();
	a = {3, 2, 1, 5, 6, 4};
	cout<< quickSelect(a, 0, a.size() - 1, 6) << endl;
	return 0;
}
