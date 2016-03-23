
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
    //reference: this one is easier to understand: https://leetcode.com/discuss/44635/accepted-recursive-solution-in-c
    struct TreeNode * prev = NULL;
    struct TreeNode * target1 = NULL;
    struct TreeNode * target2 = NULL;
    void inorder(struct TreeNode * root) {
        if (!root)
            return;
        inorder(root->left);
        
        if (prev == NULL) {
            prev = root;
        }
        else {
            if (prev != NULL && prev->val > root->val) {
                if (target1 == NULL) {//first violation
                    target1 = prev;
                    target2 = root;
                    prev = root;
                }
                else {
                    target2 = root;
                    prev = root;
                }
            
            }
            else {
                prev = root;
            }
        }
        
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if (!root)
            return;
        inorder(root);
        if (target1 && target2)
            swap(target1->val, target2->val);
    }
};
