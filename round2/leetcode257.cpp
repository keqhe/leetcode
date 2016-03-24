
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
    //ref: https://leetcode.com/discuss/79797/2ms-java-recursive-solution-with-explaination
    void helper(struct TreeNode * root, string str, vector<string> & res) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            res.push_back(str+to_string(root->val));
        }
        helper(root->left, str+to_string(root->val)+"->", res);
        helper(root->right, str+to_string(root->val)+"->", res);
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)
            return res;
        helper(root, "", res);
        return res;
    }
};
