
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
    void helper(struct TreeNode * root, string path, int &sum) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            path.push_back(root->val+'0');
            sum += stoi(path);
            return;
        }
        if (root->left) {
            helper(root->left, path+(char)(root->val+'0'), sum);
        }
        if (root->right) {
            helper(root->right, path+(char)(root->val+'0'), sum);
        }
            
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, "", sum);
        return sum;
    }
};
