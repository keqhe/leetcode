
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
    //vmware asked this questions, 2 stacks
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<struct TreeNode*> st1;
        stack<struct TreeNode*> st2;
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        st1.push(root);
        while (!st1.empty() || !st2.empty()) {
            vector<int> level1;
            vector<int> level2;
            while(!st1.empty()) {
                struct TreeNode * curr = st1.top();
                level1.push_back(curr->val);
                st1.pop();
                if (curr->left)
                    st2.push(curr->left);//notice push left first, then right
                if (curr->right)
                    st2.push(curr->right);
            }
            if (!level1.empty())
                res.push_back(level1);
            while (!st2.empty()) {
                struct TreeNode * curr = st2.top();
                level2.push_back(curr->val);
                st2.pop();
                if (curr->right)
                    st1.push(curr->right);
                if (curr->left)
                    st1.push(curr->left);
            }
            if (!level2.empty())
                res.push_back(level2);
        }
        return res;
    }
};
