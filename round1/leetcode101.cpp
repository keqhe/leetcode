
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
    bool isSame(TreeNode * root1, TreeNode * root2) {
        if (!root1 || !root2)
            return root1 == root2;
        else if (root1->val != root2->val) return false;
        return isSame(root1->left, root2->right) && isSame(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        else
            return isSame(root->left, root->right);
    }
};
