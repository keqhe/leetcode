
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
    //ref: https://leetcode.com/discuss/68639/solutions-explanation-recursive-iterative-traversal-traversal
    //the first time we encounter (prev->val >= curr->val), first swapped node must be prev
    //the second time we encounter (prev->val >= curr->val), second swapped node must be curr
    struct TreeNode * prev = nullptr;
    struct TreeNode * first= nullptr;
    struct TreeNode * second = nullptr;
    void inorder(struct TreeNode * root) {
        if (!root)
            return;
        inorder(root->left);
        
        if (prev != NULL && prev->val >= root->val) {
            if (first == nullptr)
                first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp;
        temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};
