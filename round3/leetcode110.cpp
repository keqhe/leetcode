
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
    pair<bool, int> helper(struct TreeNode * root) {
        if (!root) 
            return make_pair(true, 0);
        pair<bool, int> left = helper(root->left);
        pair<bool, int> right = helper(root->right);
        if (left.first && right.first) {
            if (abs(left.second - right.second) <= 1)
                return make_pair(true, max(left.second, right.second)+1);
        }
        return make_pair(false, -1);
    }
    bool isBalanced(TreeNode* root) {
        pair<bool, int> res = helper(root);
        if (res.first)
            return true;
        else
            return false;
    }
};
