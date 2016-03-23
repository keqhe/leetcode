
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
    void inorder_recur(struct TreeNode * root, vector<int> & nums) {
        if (!root)
            return;
        inorder_recur(root->left, nums);
        nums.push_back(root->val);
        inorder_recur(root->right, nums);
    }
    
    void inorder_iter(struct TreeNode * root, vector<int> & nums) {
        if (!root)
            return;
        stack<struct TreeNode*> st;
        while(!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;//to the left most subtree
            }
            else {//reached the left most leaf
                root = st.top();//get the leaf's parent;
                st.pop();
                //put the parent
                nums.push_back(root->val);
                //go to the right tree
                root = root->right;
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (!root)
            return v;
        inorder_iter(root, v);
        return v;
    }
};
