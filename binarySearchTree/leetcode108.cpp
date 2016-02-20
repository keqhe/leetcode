#include<iostream>
#include<string>
#include<vector>

using namespace std;

//108. Convert Sorted Array to Binary Search Tree

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct TreeNode * helper(vector<int> & nums, int left, int right) {
        if (left > right)
            return NULL;
        if (left == right) {
            struct TreeNode * p = new TreeNode(nums[left]);
            return p;
        }
        int mid = left + (right - left)/2;
        struct TreeNode * root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid-1);
        root->right = helper(nums, mid+1, right);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};

int main() {
	class Solution sn;
	return 0;
}
