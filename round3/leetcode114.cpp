
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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        if (!root->left && !root->right)
            return;
        struct TreeNode * tmp = root->right;
        if (root->left) {
            flatten(root->left);
            root->right = root->left;
            struct TreeNode * p = root->left;
            while (p->right) {
                p = p->right;
            }
            p->right = tmp;
            root->left = NULL;
            flatten(tmp);
        }
        else {
            flatten(tmp);
        }
    }
};
