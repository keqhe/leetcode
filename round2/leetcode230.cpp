
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
    //ref: https://leetcode.com/discuss/73706/java-in-order-traversal-in-0-ms-beating-95%25
    struct TreeNode* inorder(struct TreeNode * root, int & c, int k) {
        if (!root)
            return NULL;
        struct TreeNode * left = inorder(root->left, c, k);
        if (left) return left;
        c ++;
        if (c == k)
            return root;
        return inorder(root->right, c, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return inorder(root, count, k)->val;
    }
     int kthSmallest_idea2(TreeNode* root, int k) {
     
        if (!root)
            return 0;
        int count = 0;
        stack<struct TreeNode*> st;
        while (root) {
            st.push(root);
            root = root->left;
        }
        
        while (!st.empty()) {
            struct TreeNode * p = st.top();
            st.pop();
            count ++;
            if (count == k)
                return p->val;
            p = p->right;
            while (p) {
                st.push(p);
                p = p->left;
            }
        }
     }
};
