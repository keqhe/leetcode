
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
    //ref: https://leetcode.com/discuss/75054/5ms-java-clean-solution
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        //unordered_map<int, list<int>> m; //this is WRONG because the key is not in order
        map<int, list<int>> m;
        queue<pair<struct TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        int min_col = 0;
        int max_col = 0;
        while (!q.empty()) {
            pair<struct TreeNode*, int> curr = q.front();
            q.pop();
            struct TreeNode * p = curr.first;
            int col = curr.second;
            m[col].push_back(p->val);
            if (p->left) {
                q.push(make_pair(p->left, col-1));
                min_col = min(min_col, col-1);   
            }
            if (p->right) {
                q.push(make_pair(p->right, col+1));
                max_col = max(max_col, col+1);
            }
        }
        for (auto x : m) {
            vector<int> tmp;
            for (auto y : x.second) {
                //cout << y << " ";
                tmp.push_back(y);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
