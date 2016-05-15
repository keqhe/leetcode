
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
    bool helper(struct TreeNode* root, long left, long right) {
        if (!root)
            return true;
        if (root->val <= left || root->val >= right)
            return false;
        if (helper(root->left, left, root->val) && helper(root->right, root->val, right))
            return true;
    }
    bool isValidBST(TreeNode* root) {
        long left = numeric_limits<long>::min();
        long right = numeric_limits<long>::max();
        return helper(root, left, right);
    }
};
