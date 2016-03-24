
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
    //ref: https://leetcode.com/discuss/81419/clean-java-1ms-recursive-solution
    //ref: https://leetcode.com/discuss/81419/clean-java-1ms-recursive-solution
    struct TreeNode * helper(struct TreeNode * root) {
        if (!root->left && !root->right)
            return root;
        if (root->right)
            return helper(root->right);
        else
            return helper(root->left);
    }
    void flatten(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            //flatten the left sub-tree
            flatten(root->left);
            //get the last in the left subtree
            struct TreeNode * left_last = helper(root->left);
            //set the right of left_last to root->right
            left_last->right = root->right;
            //flatten root->right
            flatten(root->right);
            root->right = root->left;
            root->left = NULL;
        }
        else {
            flatten(root->right);
        }
        
    }
};
