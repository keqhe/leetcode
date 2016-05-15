
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
    //method 1 : recursive
    void helper(struct TreeNode * root, vector<int> & res) {
        if (!root)
            return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
    vector<int> preorderTraversal_recursive(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    //method 2 : iterative
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<struct TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            else {
                struct TreeNode * curr = st.top();
                st.pop();
                root = curr->right;
            }
        }
        return res;
    }
};
