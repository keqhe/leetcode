
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
    //idea1, using recursive, DFS
    void helper(struct TreeNode * root, vector<int> & res) {
        if (root) {
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }
    }
    
    vector<int> inorderTraversal_idea1(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    //idea2: using stack do inorder traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<struct TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
