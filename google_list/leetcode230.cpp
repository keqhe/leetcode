
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
    
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int curr = 0;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                curr ++;
                if (curr == k)
                    return root->val;
                root = root->right;
            }
        }
        return 0;
    }
};
