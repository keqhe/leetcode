
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
    //naive method is to use inorder-traveral
    //but better method exists (binary search on binary search tree)
    int closestValue(TreeNode* root, double target) {
        double diff = numeric_limits<double>::max();
        int candidate;
        while (root) {
            if (abs((double)root->val - target) < diff) {
                diff = abs((double)root->val - target);
                candidate = root->val;
            } 
            if (root->val == target)
                return root->val;
            else if (root->val < target) 
                root = root->right;//the hope is there!
            else
                root = root->left;
        }
        return candidate;
    }
};
