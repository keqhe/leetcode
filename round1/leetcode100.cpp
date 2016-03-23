
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
            bool parent = true;
            bool left = true;
            bool right = true;
            if (p != NULL && q != NULL && p->val == q->val)
                parent = true;
            else if (p == NULL && q == NULL)
                parent = true;
            else
                parent = false;

            if (p != NULL && q != NULL) {
                left = isSameTree(p->left, q->left);
                right = isSameTree(p->right, q->right);
            }
            return parent && left && right;
    }
};
