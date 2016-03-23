
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
    //reference: http://www.geeksforgeeks.org/find-minimum-depth-of-a-binary-tree/
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)// leaf
            return 1;
        if (!root->left) 
            return minDepth(root->right)+1;
        if (!root->right)
            return minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    int minDepth_1(TreeNode* root) {
        if (!root)
            return 0;
        else {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            if (left == 0 || right == 0)
                return max(left, right) + 1;
            else if (left != 0 && right != 0)
                return min(left, right) + 1;
        }
    }
};
