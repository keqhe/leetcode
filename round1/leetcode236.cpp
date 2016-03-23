
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

    bool inTree(struct TreeNode* root, struct TreeNode *p) {
        if (!root)
            return false;
        if (root == p)
            return true;
        return inTree(root->left, p) || inTree(root->right, p);
    }
    //Bottom up version
    //Key idea: We traverse from the bottom, and once we reach a node which matches one of the two nodes, we pass it up to its parent.
    //O(N)
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        if (p == root || q == root)
            return root;
        struct TreeNode * L = lowestCommonAncestor(root->left, p, q);
        struct TreeNode * R = lowestCommonAncestor(root->right, p, q);
        if (L && R)
            return root;
        return L ? L : R;
    }
    //Time Limit Exceeded version
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        if (!p && q)
            return q;
        else if (p && !q)
            return p;
        else if (!p && !q)
            return NULL;
            
        if (p == root || q == root)
            return root;
        bool left_p = inTree(root->left, p);
        bool right_q = inTree(root->right, q);
        bool right_p = inTree(root->right, p);
        bool left_q = inTree(root->left, q);
        if (left_p && right_q)
            return root;
        else if (right_p && left_q)
            return root;
        else if (left_p && left_q)
            return lowestCommonAncestor(root->left, p, q);
        else if (right_p && right_q)
            return lowestCommonAncestor(root->right, p, q);
    }
    
    //by this acticle:
    int countMatchesPQ(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return 0;
        int matches = countMatchesPQ(root->left, p, q) + countMatchesPQ(root->right, p, q);
        if (root == p || root == q)
            return 1 + matches;
        else
            return matches;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return NULL;
        if (root == p || root == q) return root;
        int totalMatches = countMatchesPQ(root->left, p, q);
        if (totalMatches == 1)
            return root;
        else if (totalMatches == 2)
            return lowestCommonAncestor(root->left, p, q);
        else /* totalMatches == 0 */
            return lowestCommonAncestor(root->right, p, q);
    }
    
};
