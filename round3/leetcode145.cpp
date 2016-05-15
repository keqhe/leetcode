
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
        helper(root->left, res);
        helper(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal_recursive(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    //method 2: iterative
    //key idea: using list and reverse it
     vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
            
        list<int> l;
        stack<struct TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                l.push_front(root->val);//push it to head of the list
                st.push(root);
                root = root->right;
            }
            else {
                struct TreeNode * curr = st.top();//curr->right must be NULL
                st.pop();
                root = curr->left;
            }
        }
        for (auto it = l.begin(); it != l.end(); it ++)
            res.push_back(*it);
        return res;
     }
};
