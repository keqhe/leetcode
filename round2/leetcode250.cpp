
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

    bool helper(struct TreeNode * root, int &count) {
        if (!root)
            return true;
        if (!root->left && !root->right) {
            count ++;
            return true;
        }
        bool left = helper(root->left, count);
        bool right = helper(root->right, count);
        if (root->left && !root->right) {
            if (root->val == root->left->val && left) {
                count ++;
                return true;
            }
        }
        else if (root->right && !root->left) {
            if (root->val == root->right->val && right) {
                count ++;
                return true;
            }
        }
        else {
            if (root->val == root->right->val && root->val == root->left->val && left && right) {
                count ++;
                return true;
            }
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        if (!root)
            return 0;
        int count = 0;
        helper(root, count);
        return count;
    }
};
