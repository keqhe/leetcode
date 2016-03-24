
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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 && right == 0)
            return 1;
        else if (left != 0 && right == 0) {
            return left + 1;
        }
        else if (right != 0 && left == 0) {
            return right + 1;
        }
        else {
            return min(left, right) + 1;
        }
    }
};
