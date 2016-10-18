
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> m;
        if (!root)
            return {};
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            m[curr.second].push_back(curr.first->val);
            if (curr.first->left) {
                q.push(make_pair(curr.first->left, curr.second-1));
            }
            if (curr.first->right) {
                q.push(make_pair(curr.first->right, curr.second+1));
            }
        }
        vector<vector<int>> res;
        for (const auto & kv : m) {
            res.push_back(kv.second);
        }
        return res;
    }
};
