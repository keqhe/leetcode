
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
    //reference: https://leetcode.com/discuss/74359/4-line-c-simple-solution-easy-understanding
    //is it recursive or DFS? recursive is DFS, right?
    bool helper(struct TreeNode * root, long low, long high) {
        if (!root)
            return true;
        return (low < root->val) && (root->val < high) && helper(root->left, low, root->val) && 
        helper(root->right, root->val, high);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
};
