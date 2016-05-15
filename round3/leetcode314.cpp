
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
        vector<vector<int>> res;
        if (!root)
            return res;
        
        map<int, vector<int>> m;//key is column, value is number array
        queue<pair<struct TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i ++) {
                pair<struct TreeNode*, int> t = q.front();
                q.pop();
                struct TreeNode * curr = t.first;
                int col = t.second;
                m[col].push_back(curr->val);
                if (curr->left)
                    q.push(make_pair(curr->left, col-1));
                if (curr->right)
                    q.push(make_pair(curr->right, col+1));
            }
        }
        
        for (auto kv : m) {
            res.push_back(kv.second);
        }
        return res;
    }
};
