
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
    TreeNode* inorderSuccessor1(TreeNode* root, TreeNode* p) {
        if (!root)
            return nullptr;
        if (p->right) {
            TreeNode* q = p->right;
            while(q->left) {
                q = q->left;
            }
            return q;
        }
        else {
            TreeNode * found = nullptr;
            while (root) {
                if (root->val > p->val) {
                    found = root;
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return found;
        }
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root)
            return nullptr;
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        }
        else {
            TreeNode* q = inorderSuccessor(root->left, p);
            if (q)
                return q;
            else
                return root;
        }
    }
};
