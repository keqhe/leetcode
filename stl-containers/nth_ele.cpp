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
	nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
	printVector(nums);

	//find the second largest element in O(n)
	nth_element(nums.begin(), nums.begin()+1, nums.end(), greater<int>());
	printVector(nums);

	return 0; 
}
