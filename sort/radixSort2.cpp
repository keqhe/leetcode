#include<iostream>
#include<string>
#include<vector>

using namespace std;

//time complexity is O(d(n+k)), where d is the number of digits, n is number count, k is the number of availdable digits
void radixSort(vector<int> & nums) {
	if (nums.empty())
		return;	
	int max_val = nums[0];
	for (auto x : nums)
		if (x > max_val)
			max_val = x;
	int base = 1;
	vector<int> B(nums.size(), 0);
	while (max_val / base > 0) {
		vector<int> counts(10, 0);
		for (int i = 0; i < nums.size(); i ++) {
			int front = nums[i] / base;
			int digit = front % 10;
			counts[digit] ++;
		}
		for (int i = 1; i < counts.size(); i ++) {
			counts[i] = counts[i] + counts[i-1];
		}
		for (int i = nums.size()-1; i >= 0; i --) {
			int front = nums[i] / base;
			int digit = front % 10;
			int pos = -- counts[digit];
			B[pos] = nums[i];
		}
		for (int i = 0; i < nums.size(); i ++)
			nums[i] = B[i];
		base *= 10;
	}
}

void printVector(vector<int> & nums) {
        for (auto x : nums)
                cout << x << " ";
        cout << endl;
}
int main() {
        vector<int> nums = {1001, 1002, 1001, 503, 209, 1200};
        printVector(nums);
        radixSort(nums);
        printVector(nums);
        return 0;
}
