
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
    //https://discuss.leetcode.com/topic/60403/java-iterative-and-recursive-solutions
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        int res = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right)
                res += root->left->val;
            else {
                res += sumOfLeftLeaves(root->left);
            }
        }
        if (root->right) {
            res += sumOfLeftLeaves(root->right);
        }
        return res;
    }
};
