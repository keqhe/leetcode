
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
    //ref: https://leetcode.com/discuss/52210/c-one-pass-recursive-solution
    bool helper(struct TreeNode * root, int & count) {
        if (!root)
            return true;
        bool left = helper(root->left, count);
        bool right = helper(root->right, count);
        if (left && right) {
            if (!root->left && !root->right) {
                count ++;
                return true;
            }
            else if (root->left && !root->right) {
                if (root->left->val == root->val) {
                    count ++;
                    return true;
                }
            }
            else if (root->right && !root->left) {
                if (root->right->val == root->val) {
                    count ++;
                    return true;
                }
            }
            else {
                if (root->val == root->left->val && root->val == root->right->val) {
                    count ++;
                    return true;
                }
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
