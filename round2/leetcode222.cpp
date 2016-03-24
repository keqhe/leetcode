
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
    //complete binary tree, except for the bottom layer, all layers are full
    //O(h^2) solution
    int getLeftHeight(struct TreeNode * root) {
        int res = 0;
        while (root) {
            res ++;
            root = root->left;
        }
        return res;
    }
    int getRightHeight(struct TreeNode * root) {
        int res = 0;
        while (root) {
            res ++;
            root = root->right;
        }
        return res;
    }
    
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int l = getLeftHeight(root);
        int r = getRightHeight(root);
        if (l == r)
            return (1 << l) - 1;
        else 
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
    ////TLE version
    int countNodes_TLE(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
