#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

//put the correct element at the position specified by the second parameter as if it was sorted
//average complexity is O(N)

void printVector(vector<int> & nums) {
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it ++) {
		cout << *it << ' ';
	}
	cout << endl;
}
int main() {
	vector<int> nums {1, 9, 7, 0, 3, 10};
	vector<int>::iterator it = next(nums.begin(), nums.size()/2);
	cout << "it points to " << *it << endl;

	nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
	printVector(nums);

	//find the second largest element in O(n)
	nth_element(nums.begin(), nums.begin()+1, nums.end(), greater<int>());
	printVector(nums);

	nums = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        printVector(nums);

	nums = {1, 5, 4, 2, 3};
	//i think below is the correct way to find median, not nums.size()/2...
	vector<int>::iterator nth = next(nums.begin(), (nums.size()-1)/2);
	cout << "nth points to " << *nth << endl;
	nth_element(nums.begin(), nth, nums.end());
	printVector(nums);

	return 0; 
}
