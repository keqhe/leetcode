
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
    void invertTreeHelper(struct TreeNode * curr) {
        if (!curr)
            return;
        struct TreeNode * temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        
        invertTreeHelper(curr->left);
        invertTreeHelper(curr->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root);
        return root;
    }
};
