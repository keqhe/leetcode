
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
    bool helper(struct TreeNode * root1, struct TreeNode * root2) {
        if (!root1 && !root2)
            return true;
        else if (!root1 || !root2)
            return false;
        return (root1->val == root2->val) && helper(root1->left, root2->right) && helper(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }
};
