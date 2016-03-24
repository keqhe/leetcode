
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
    //4 line solution...
    //see ref: https://leetcode.com/discuss/85004/easy-c-4-lines
    
    //node has unique value
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        
        int a = root->val - p->val;
        int b = root->val - q->val;
        if (a*b <= 0)
            return root;
        else if (a > 0 && b > 0) 
            return lowestCommonAncestor(root->left, p, q);
        else if (a < 0 && b < 0)
            return lowestCommonAncestor(root->right, p, q);
    }
};
