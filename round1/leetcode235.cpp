
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        if (!p && q)
            return q;
        else if (p && !q)
            return p;
        else if (!p && !q)
            return NULL;
            
        struct TreeNode * start = root;
        while(start) {
            if (p->val < start->val && q->val < start->val)
                start = start->left;
            else if (p->val > start->val && q->val > start->val)
                start = start->right;
            else
                break;
        }
        return start;
    }
};
