
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
    //note there must be no duplicate numbers in the binary tree, otherwise, the following method does not make sense
    struct TreeNode * helper(vector<int>& inorder, int p1, int p2, vector<int>& postorder, int q1, int q2) {
        if (q1 > q2 || p1 > p2)
            return NULL;
        if (q1 == q2) {
            struct TreeNode * root = new TreeNode(postorder[q1]);
            return root;
        }
        int root_val = postorder[q2];
        struct TreeNode * root = new TreeNode(root_val);
        int i = p1;
        for (i = p1; i <= p2; i ++) {
            if (inorder[i] == root_val)
                break;
        }
        int left_size = i-p1;
        int right_size = p2-i;
        root->left = helper(inorder, p1, i-1, postorder, q1, q1+left_size-1);
        root->right = helper(inorder, i+1, p2, postorder, q2-right_size, q2-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
