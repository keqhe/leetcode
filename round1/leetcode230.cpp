
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
    //use inorder traversal, iterative version
    int kthSmallest(TreeNode* root, int k) {
        stack<struct TreeNode*> st;
        int n = 0;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                if (root) {
                    n ++;
                    if (n == k)
                        return root->val;
                }
                root = root->right;
            }
        }
        
    }
};
