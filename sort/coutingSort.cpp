#include<iostream>
#include<string>
#include<vector>

using namespace std;

//couting sort, assumes A's elements belong to [0,k] where k is the max of A[:]
//time complexity is O(n+k), if k = O(n) (ie., k is not too large), then it is O(n)
//space complexity is also O(n)
//couting sort is stable sort
vector<int> countingSort(vector<int> & A) {
	int k = 0;
	for (int i = 0; i < A.size(); i ++) {
		k = max(k, A[i]);
	}
	vector<int> C (k+1, 0);//e.g., k is 2, even k = 0, that's also fine
	for (int i = 0; i < A.size(); i ++) {
		C[A[i]] += 1;
	}

	for (int i = 1; i < C.size(); i ++) {
		C[i] = C[i] + C[i-1];
	}
	//now C[i] means the number of elements that are smaller or equal to i
	vector<int> B (A.size(), 0);
	for (int i = A.size() - 1; i >= 0; i --) {//in order to be stable sort
		int val = A[i];
		int pos = -- C[val];//because index from 0
		B[pos] = val;
	}
	return B;
}

void printVector(vector<int> & nums) {
	for (int i = 0; i < nums.size(); i ++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}
int main() {
	vector<int> nums = {2, 5, 3, 0, 2, 3, 0, 3};
	printVector(nums);
	nums = countingSort(nums);
	printVector(nums);
	return 0;
}
