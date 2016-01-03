#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> radixSort(vector<int> & nums) {
	if (nums.size() <= 1)
		return nums;
	int base = 1;//1, 10, 100, 1000
	int m = 0;//the maximal element in nums
	for (int i = 0; i < nums.size(); i ++) {
		m = max(m, nums[i]);
	}
	vector<int> B(nums.size());
	while (m / base > 0) {// go through all of the bits from LSB to MSB
		vector<int> C(10); //0 to 9, represent each bit
		for (int i = 0; i < nums.size(); i ++) {
			int digit = (nums[i] / base) % 10;
			C[digit] += 1;
		}

		for (int i = 1; i < 10; i ++) {
			C[i] = C[i] + C[i-1];
		}
		//now C[i] means the number of elements that are smaller or equal to i
		for (int i = nums.size()-1; i >= 0; i --) {
			int digit = (nums[i] / base) % 10;
			int pos = --C[digit];
			B[pos] = nums[i];
		}
		for (int i = 0; i < nums.size(); i ++) {
			nums[i] = B[i];
		}
		base *= 10;
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
	vector<int> nums = {1001, 102, 110, 210, 540};
	printVector(nums);
	nums = radixSort(nums);
	printVector(nums);
	
	nums = {100, 3, 2, 1};
	printVector(nums);
        nums = radixSort(nums);
        printVector(nums);
	return 0;		
}

