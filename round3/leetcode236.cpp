
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
    //the following naive solution meets TLE, will a cache save it? maybe
    bool inTree(struct TreeNode* root, struct TreeNode *p) {
        if (!root)
            return false;
        if (root == p)
            return true;
        return inTree(root->left, p) || inTree(root->right, p);
    }
    TreeNode* lowestCommonAncestor_tle(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        bool pleft = inTree(root->left, p);
        bool qleft = inTree(root->left, q);
        bool pright = inTree(root->right, p);
        bool qright = inTree(root->right, q);
        
        if (pleft && qright || pright && qleft)
            return root;
        else if (pleft && qleft)
            return lowestCommonAncestor(root->left, p, q);
        else if (pright && qright)
            return lowestCommonAncestor(root->right, p, q);
        else 
            return NULL;
    }
    /*
    idea:Bottom
    We traverse from the bottom, 
    and once we reach a node which matches one of the two nodes, we pass it up to its parent.
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        if (root == p || root == q)
            return root;
        struct TreeNode * left = lowestCommonAncestor(root->left, p, q);
        struct TreeNode * right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        else if (left)
            return left;
        else
            return right;
    }
};
