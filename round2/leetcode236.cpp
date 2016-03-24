
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
    //ref: https://leetcode.com/discuss/82443/concise-4-line-c
    //assume that both p and q are in the binary tree
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        
        if (root == p || root == q)
            return root;
        struct TreeNode * l = lowestCommonAncestor(root->left, p, q);
        struct TreeNode * r = lowestCommonAncestor(root->right, p, q);
        if (l && r) //they are in left and right respectively
            return root;
        else if (l)
            return l;
        else
            return r;
    }
};
