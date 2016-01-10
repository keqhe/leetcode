#include<iostream>
#include<string>
#include<vector>

using namespace std;

int partition(vector<int> & nums, int left, int right) {
	//int mid = (left + right) / 2; //this may overflow for large left and right
	int mid = left + (right - left) / 2;
	int x = nums[mid];
	int i = left;
	int j = right;
	while(i <= j) {
		while(nums[i] > x)// change here to determine the order!! 
			i ++;
		while(nums[j] < x)
			j --;
		if (i <= j) {
			int t = nums[i];
			nums[i] = nums[j];
			nums[j] = t;
			i ++;
			j --;
		}
	}
	return i;
} 

void quickSort(vector<int> & nums, int left, int right) {
	if (left < right) {
		int p = partition(nums, left, right);
		quickSort(nums, left, p - 1);
		quickSort(nums, p, right);
	}
}

void printVector(vector<int> & nums) {
	for (int i = 0; i < nums.size(); i ++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}

int main() {
	vector<int> v = {1, 4, 2, 7, 5, 0};
	printVector(v);
	quickSort(v, 0, v.size() - 1);
	printVector(v);

	return 0;
}
