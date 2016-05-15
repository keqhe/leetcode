
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
    //the key here is that there is no duplicated values in the tree, otherwise, it does not work
    struct TreeNode * helper(vector<int>& preorder, int p1, int p2, vector<int>& inorder, int q1, int q2) {
        if (p1 > p2 || q1 > q2)
            return NULL;
        if (p1 == p2) {
            struct TreeNode * root = new TreeNode(preorder[p1]);
            return root;
        }
        int root_val = preorder[p1];
        struct TreeNode * root = new TreeNode(root_val);
        int i;//i is the root in the inorder sequence
        for (i = q1; i <= q2; i ++) {
            if (root_val == inorder[i])
                break;
        }
        int left_size = i-q1; //i-1-q1+1;
        int right_size = q2-i; //q2-(i+1)+1;
        root->left = helper(preorder, p1+1, p1+left_size, inorder, q1, i-1);
        root->right = helper(preorder,p2-right_size+1, p2, inorder, i+1, q2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size())//invalid input
            return NULL;
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
