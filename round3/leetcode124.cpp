
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(struct TreeNode* root, int &maxSum) {
        if (!root) 
            return 0;
        int a = helper(root->left, maxSum);
        int b = helper(root->right, maxSum);
        int sub_max = max(max(a+root->val, b+root->val), root->val);
        int curr_max = max(root->val+a+b, sub_max);
        maxSum = max(maxSum, curr_max);
        return sub_max;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = numeric_limits<int>::min();
        int res = helper(root, maxSum);
        return maxSum;
    }
};
