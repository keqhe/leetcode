
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
    //this kind of problem most likely use recursion, this should be the first thought
    //using an exam to drive the code
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root)
            return NULL;
        if (!root->left && !root->right)
            return root;
        struct TreeNode * right = root->right;//right is either NULL or a leaf
        struct TreeNode * left = upsideDownBinaryTree(root->left);
        struct TreeNode * p = left;
        while (p->right) {
            p = p->right;
        }
        p->right = root;
        root->left = NULL;//important, cut the old connections of root
        root->right = NULL;//important, cut the old connections of root
        p->left = right;
        return left;
    }
};
