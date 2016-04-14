
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
    //i met this problem when interviewed with VMware, idea is to use two stacks
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        stack<struct TreeNode*> l2r;
        stack<struct TreeNode*> r2l;
        l2r.push(root);
        int level = 0;
        //when level is even, process from left to right, 
        //when level is odd, process from right to left
        while (!l2r.empty() || !r2l.empty()) {
            vector<int> this_level;
            struct TreeNode * curr;
            if (level % 2 == 0) {
                while (!l2r.empty()) {
                    curr = l2r.top();
                    l2r.pop();
                    this_level.push_back(curr->val);
                    if (curr->left)
                        r2l.push(curr->left);
                    if (curr->right)
                        r2l.push(curr->right);
                }
            }
            else if (level % 2 == 1) {
                while (!r2l.empty()) {
                    curr = r2l.top();
                    r2l.pop();
                    this_level.push_back(curr->val);
                    if (curr->right)
                        l2r.push(curr->right);
                    if (curr->left)
                        l2r.push(curr->left);
                }
            }
            res.push_back(this_level);
            level ++;
        }
        return res;
    }
};
