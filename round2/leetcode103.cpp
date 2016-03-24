
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        stack<struct TreeNode*> st0;
        stack<struct TreeNode*> st1;
        int level = 0;
        st0.push(root);
        while (!st0.empty() || !st1.empty()) {
            int size;
            if (level % 2 == 0) {
                size = st0.size();
                vector<int> tmp;
                for (int i = 0; i < size; i ++) {
                    struct TreeNode * p = st0.top();
                    st0.pop();
                    if (p->left)
                        st1.push(p->left);
                    if (p->right)
                        st1.push(p->right);
                    tmp.push_back(p->val);
                }
                res.push_back(tmp);
            }
            else {
                size = st1.size();
                vector<int> tmp;
                for (int i = 0; i < size; i ++) {
                    struct TreeNode * p = st1.top();
                    st1.pop();
                    if (p->right)
                        st0.push(p->right);
                    if (p->left)
                        st0.push(p->left);
                    tmp.push_back(p->val);
                }
                res.push_back(tmp);
            }
            level ++;
        }
        return res;
    }
};
