
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if (!root)
            return v;
        stack<struct TreeNode*> st;
        while(!st.empty() || root) {
            if (root) {
                v.push_back(root->val);
                if (root->right)
                    st.push(root->right);
                root = root->left;//to left most leaf
            }
            else {//reached the left most leaf
                struct TreeNode *p = st.top();
                st.pop();
                root = p;//go to the right subtree
            }
        }
        return v;
    }
};
