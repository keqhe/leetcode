
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
    struct TreeNode * helper(vector<int>&inorder, vector<int>&postorder, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2)
            return NULL;
        struct TreeNode * root = new TreeNode(postorder[e2]);
        if (s2 == e2)
            return root;
        int index;
        for (int i = s1; i <= e1; i ++) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        root->left = helper(inorder, postorder, s1, index-1, s2, s2+index-s1-1);
        root->right = helper(inorder, postorder, index+1, e1, s2+index-s1, e2-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
