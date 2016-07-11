
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
    /*
        3
      2   4
    3
    */
    int max_value = 0;
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right) {
            max_value = max(max_value, 1);
            return 1;
        }
        int res = 1;
        int left = helper(root->left);
        int right = helper(root->right);
        
        if (root->left && root->left->val == root->val+1) {
            res = max(res, left+1);
        }
        if (root->right && root->right->val == root->val+1) {
            res = max(res, right+1);
        }
        max_value = max(max_value, res);
        return res;
    }
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return max_value;
    }
};
