
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
    //think why the following is wrong
    int minDepth_wrong(TreeNode* root) {
        if (!root)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return min(left, right)+1;
    }
    //method 1
    int helper(struct TreeNode* root) {
        if (!root)
            return numeric_limits<int>::max();
        if (!root->left && !root->right)
            return 1;
        int left = helper(root->left);
        int right = helper(root->right);
        
        return min(left, right)+1;
    }
    int minDepth_method1(TreeNode* root) {
        int res = helper(root);
        return res == numeric_limits<int>::max() ? 0 : res;
    }
    //method 2
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int left = helper(root->left);
        int right = helper(root->right);
        if (left == 0 && right == 0)
            return 1;
        else if (left == 0)
            return right + 1;
        else if (right == 0)
            return left + 1;
        else 
            return min(left, right) + 1;
    }
};
