
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
    pair<int, bool> helper (struct TreeNode * root) {
        if (!root) {
            pair<int,bool> tmp (0, true);
            return tmp;
        }
        pair<int,bool> left = helper(root->left);
        pair<int,bool> right = helper(root->right);
        if (left.second && right.second && abs(left.first-right.first) <= 1) {
            return make_pair(max(left.first, right.first)+1, true);
        }
        else
            return make_pair(0, false);
    }
    bool isBalanced(TreeNode* root) {
        pair<int, bool> res = helper(root);
        return res.second;
    }
};
