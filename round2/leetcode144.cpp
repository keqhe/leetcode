
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
    //idea 1, using recursive
    void helper(struct TreeNode * root, vector<int> & res) {
        if (root) {
            res.push_back(root->val);
            helper(root->left, res);
            helper(root->right, res);
        }
    }
    vector<int> preorderTraversal_idea1(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<struct TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return res;
    }
};
