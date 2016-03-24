
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
    vector<struct TreeNode*> helper(int l, int r) {
        vector<struct TreeNode*> res;
        if (l > r) {
            res.push_back(NULL);//important
            return res;
        }
        if (l == r) {
            struct TreeNode * p = new TreeNode(l);
            res.push_back(p);
            return res;
        }
        
        for (int i = l; i <= r; i ++) {
            vector<struct TreeNode*> lefts = helper(l, i-1);
            vector<struct TreeNode*> rights = helper(i+1, r);
            for (auto x : lefts) {
                for (auto y: rights) {
                    struct TreeNode * root = new TreeNode (i);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        vector<struct TreeNode*> res;
        if (n == 0)
            return res;
        res = helper(1, n);
        return res;
    }
};
