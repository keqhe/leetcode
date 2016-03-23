
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<struct TreeNode*> st;
        struct TreeNode* prev = NULL;
        vector<int> v;
        if (!root)
            return v;
        st.push(root);
        while(!st.empty()) {
            struct TreeNode * curr = st.top();
            if (!prev || prev->left == curr || prev->right == curr) {
                if (curr->left)
                    st.push(curr->left);
                else if (curr->right)
                    st.push(curr->right);
                else {
                    v.push_back(curr->val);
                    st.pop();
                }
            }
            else if (curr->left == prev) {
                if (curr->right)
                    st.push(curr->right);
                else {
                    v.push_back(curr->val);
                    st.pop();
                }
            }
            else if (curr->right == prev) {
                v.push_back(curr->val);
                st.pop();
            }
            
            //
            prev = curr;
        }
        return v;
    }
};
