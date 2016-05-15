
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
    //recursion 
    void helper(struct TreeNode * root, vector<int> & res) {
        if (!root)
            return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
    vector<int> inorderTraversal_recursive(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    //iterative solution
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<struct TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                struct TreeNode * curr = st.top();//curr->left must be NULL
                st.pop();
                res.push_back(curr->val);
                root = curr->right;
            }
        }
        return res;
    }
};
