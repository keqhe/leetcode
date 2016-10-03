
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
    pair<int, int> helper(TreeNode * root) {
        if (!root)
            return make_pair(0, 0);
        if (!root->left && !root->right)
            return make_pair(root->val, 0);
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        
        int a = root->val + left.second + right.second;
        int b = max(left.first, left.second) + max(right.first, right.second);
        return make_pair(a, b);
    }
    int rob(TreeNode* root) {
        pair<int, int> res = helper(root);
        return max(res.first, res.second);
    }
};
