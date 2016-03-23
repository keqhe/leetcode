
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
    //ref: recursive, https://leetcode.com/discuss/52414/c-recursive-solution-easy-understanding
    //ref: iterative, https://leetcode.com/discuss/18410/easy-o-n-iteration-solution-java
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left)
            return root;
        struct TreeNode * curr_left = root->left;
        struct TreeNode * curr_right = root->right;
        struct TreeNode *newroot = upsideDownBinaryTree(root->left);
        
        curr_left->left = curr_right;
        curr_left->right = root;
        root->left = NULL;
        root->right = NULL;
        
        return newroot;
    }
};
