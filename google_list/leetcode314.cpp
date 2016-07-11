
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
        map<int, vector<int>> tmp;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                pair<TreeNode*, int> curr = q.front();
                q.pop();
                TreeNode * p = curr.first;
                int pos = curr.second;
                tmp[pos].push_back(p->val);
                if (p->left)
                    q.push(make_pair(p->left, pos-1));
                if (p->right)
                    q.push(make_pair(p->right, pos+1));
            }
        }
        for (auto kv : tmp) {
            res.push_back(kv.second);
        }
        return res;
    }
};
