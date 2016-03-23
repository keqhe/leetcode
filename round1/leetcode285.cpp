
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
    //ref1: http://stackoverflow.com/questions/5471731/in-order-successor-in-binary-search-tree
    //ref2: https://leetcode.com/discuss/59728/10-and-4-lines-o-h-java-c
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p)
            return NULL;
        //case 1, p has a right subtree
        if (p->right) {
            p = p->right;
            while (p->left)
                p = p->left;
            return p;
        } 
        struct TreeNode * candidate = NULL;
        while (root != p) {
            if (p->val > root->val)
                root = root->right;
            else {
                candidate = root;
                root = root->left;
            }
        }
        return candidate;
    }
};
