#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printVector(vector<int> & nums);

void merge(vector<int> &nums, int left, int mid, int right) {
	cout << "merge: left, mid, right " << left << ' ' << mid << ' ' << right << endl;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	vector<int> t1 (n1, 0);
	vector<int> t2 (n2, 0);
	
	for (int i = 0; i < n1; i ++) {
		t1[i] = nums[left + i];
	}
	for (int i = 0; i < n2; i ++) {
		t2[i] = nums[mid + 1 + i];
	}

	//printVector(t1);
	//printVector(t2);

	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (t1[i] <= t2[j]) {
			nums[k] = t1[i];
			k ++;
			i ++;
		}
		else {
			nums[k] = t2[j];
			k ++;
			j ++;
		}
	}

	while (i < n1) {
		nums[k] = t1[i];
		k ++;
		i ++;	
	}

	while (j < n2) {
		nums[k] = t2[j];
		k ++;
		j ++;
	}
}

void mergeSort(vector<int> & nums, int left, int right) {
	if (left < right) {
		//int mid = (left + right) / 2;//this may overflow
		int mid = left + (right - left) / 2; //avoid overflow for large left, right
		cout << "left, mid and right are " << left <<' ' << mid << ' '<< right << endl;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

void printVector(vector<int> & nums) {
	for (int i = 0; i < nums.size(); i ++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}

int main() {
	vector<int> v = {1, 3, 2, 9, 0, 7};
	printVector(v);
	mergeSort(v, 0, v.size() - 1);
	printVector(v);

	return 0;	
}
