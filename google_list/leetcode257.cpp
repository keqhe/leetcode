
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
    void helper(TreeNode * root, string path, vector<string>& res) {
        if (!root)
            return;
        if (path.empty())
            path += to_string(root->val);
        else
            path += "->" + to_string(root->val);
        
        if (!root->left && !root->right) {
            res.push_back(path);
        }
        else {
            if (root->left && root->right) {
                helper(root->left, path, res);
                helper(root->right, path, res);
            }
            else if (root->left)
                helper(root->left, path, res);
            else
                helper(root->right, path, res);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)
            return res;
        helper(root, "", res);
        return res;
    }
};
