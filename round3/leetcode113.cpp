
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
    void helper(struct TreeNode * root, vector<int> path, int leftover, vector<vector<int>> & res) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            if (leftover == root->val) {
                path.push_back(root->val);
                res.push_back(path);
            }
        }
        path.push_back(root->val);
        helper(root->left, path, leftover-root->val, res);
        helper(root->right, path, leftover-root->val, res);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper(root, path, sum, res);
        return res;
    }
};
