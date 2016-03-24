
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
    void helper(struct TreeNode * root, int sum, int curr, vector<int> path, vector<vector<int>> & res) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            if (curr + root->val == sum) {
                path.push_back(root->val);
                res.push_back(path);
                return;
            }
        }
        path.push_back(root->val);
        helper(root->left, sum, curr+root->val, path, res);
        helper(root->right, sum, curr+root->val, path, res);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> path;
        helper(root, sum, 0, path, res);
        return res;
    }
};
