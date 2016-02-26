#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int helper(struct TreeNode * root, int & count) {
        if (!root)
            return 0;
        if (!root->left && !root->right) {
            if (1 > count) //missed this corner case initially
                count = 1;
            return 1;
        }
        int leftCount = helper(root->left, count);
        int rightCount = helper(root->right, count);
        int curr;
        
        if (root->left && root->val + 1 == root->left->val && 
            root->right && root->val + 1 == root->right->val) {
            curr = max(leftCount, rightCount) + 1;
            if (curr > count)
                count = curr;
            return curr;
        }
        else if (root->left && root->val + 1 == root->left->val) {
            curr = leftCount + 1;
            if (curr > count)
                count = curr;
            return curr;
        }
        else if (root->right && root->val + 1 == root->right->val) {
            curr = rightCount + 1;
            if (curr > count)
                count = curr;
            return curr;
        }
        else {
            curr = 1;
            if (curr > count)
                count = curr;
            return curr;
        }
    }
    int longestConsecutive(TreeNode* root) {
        int count  = 0;
        helper(root, count);
        return count;
    }
};

int main() {
	class Solution sn;
	return 0;
}
