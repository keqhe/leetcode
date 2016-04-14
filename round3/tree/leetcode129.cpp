
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
    void helper(struct TreeNode * root, int curr, int & sum) {
        if (!root)
            return;
        curr = curr*10 + root->val;
        if (!root->left && !root->right) {
            sum += curr;
            return;
        }
        helper(root->left, curr, sum);
        helper(root->right, curr, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
};
