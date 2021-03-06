
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
    void helper(TreeNode* root, vector<string> & res, string path) {
        if (!root)
            return;
        if (!path.empty()) {
            path += "->" + to_string(root->val);
        }
        else {
            path = to_string(root->val);
        }
            
        if (!root->left && !root->right) {
            res.push_back(path);
        }
        
        helper(root->left, res, path);
        helper(root->right, res, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, res, "");
        return res;
    }
};
