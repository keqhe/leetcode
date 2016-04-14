
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
    //straitforward solution is O(n)
    int kthSmallest(TreeNode* root, int k) {
        stack<struct TreeNode*> st;
        int cnt = 0;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                struct TreeNode * curr = st.top();//curr->left must be NULL
                st.pop();
                cnt ++;
                if (cnt == k)
                    return curr->val;
                root = curr->right;
            }
        }
    }
};
