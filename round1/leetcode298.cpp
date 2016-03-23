
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
    //post order, recursive
    //ref: https://leetcode.com/discuss/67450/easy-java-solution
    int helper(struct TreeNode * root, int &count) {
        if (!root)
            return 0;
        
        int left = helper(root->left, count);
        int right = helper(root->right, count);
        if (!root->left || (root->val + 1) != root->left->val) 
            left = 0;
        if (!root->right || (root->val + 1) != root->right->val)
            right = 0;
        int res = max(left, right) + 1;
        count = max(count, res);
        return res;
    }
    int longestConsecutive(TreeNode* root) {
        int count = 0;
        helper(root, count);
        return count;
    }
};
