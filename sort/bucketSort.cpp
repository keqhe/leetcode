#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void bucketSort(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int min_val = nums[0];
        int max_val = nums[0];
        for (auto x : nums) {
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }
        max_val ++; //in case max_val == min_val;
        int len = nums.size();
        vector<vector<int>> tmp(len, vector<int>());
        for (int i = 0; i < nums.size(); i ++) {
            int index = len*((double)(nums[i]-min_val)/(max_val-min_val));
            tmp[index].push_back(nums[i]);
        }
        for (int i = 0; i < tmp.size(); i ++)
            sort(tmp[i].begin(), tmp[i].end());
        int k = 0;
        for (int i = 0; i < tmp.size(); i ++) {
            for (int j = 0; j < tmp[i].size(); j ++) {
                nums[k++] = tmp[i][j];
            }
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
        bucketSort(nums);
        printVector(nums);
        return 0;
}
