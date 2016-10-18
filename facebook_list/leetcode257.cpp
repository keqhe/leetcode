
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
    void dfs(TreeNode* root, string s, vector<string>& res) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            s += s.empty() ? to_string(root->val) : "->" + to_string(root->val);
            res.push_back(s);
            return;
        }
        if (root->left) {
            dfs(root->left, s.empty() ? to_string(root->val) : s + "->" + to_string(root->val), res);
        }
        if (root->right) {
            dfs(root->right, s.empty() ? to_string(root->val) : s + "->" + to_string(root->val), res);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return {};
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};
