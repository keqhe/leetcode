
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
    //ref: https://leetcode.com/discuss/63586/neat-java-solution-pretty-easy-to-read
    //idea: recursion
    struct TreeNode * helper(vector<int> & preorder, vector<int> & inorder, int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end)
            return NULL;
        struct TreeNode * root = new TreeNode(preorder[pre_start]);
        if (pre_start == pre_end) {
            return root;
        }
        int index;
        for (int i = in_start; i <= in_end; i ++) {
            if (root->val == inorder[i]) {
                index = i;
                break;
            }
        }
        root->left = helper(preorder, inorder, pre_start+1, pre_start+(index-in_start), in_start, index-1);
        root->right = helper(preorder, inorder, pre_start+(index-in_start)+1, pre_end, index+1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
