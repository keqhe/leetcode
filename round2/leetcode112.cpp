
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
    bool helper(struct TreeNode * root, int now, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right) {
            if ((now + root->val) == sum)
                return true;
            else
                return false;
        }
        return helper(root->left, now+root->val, sum) || helper(root->right, now+root->val, sum); 
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;//[] and 0 test case
        return helper(root, 0, sum);
    }
};
