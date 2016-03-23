
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
    void helper(struct TreeNode* root, string s, int &sum) {
        s += to_string(root->val);
        
        if (!root->left && !root->right) {
            sum += stoi(s);
        }
        
        if (root->left)
            helper(root->left, s, sum);
        if (root->right)
            helper(root->right, s, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (!root)
            return 0;
        string s;
        helper(root, s, sum);
        return sum;
    }
};
