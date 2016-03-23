
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
    void helper(struct TreeNode * root, vector<int> path, int sum, vector<vector<int>> & res) {
        int total = 0;
        for (int i = 0; i < path.size(); i ++)
            total += path[i];
            
        if (!root->left && !root->right) {
            if (total + root->val == sum) {
                path.push_back(root->val);
                res.push_back(path);
            }
        }
        //root still has child
        /*
        if (sum >= 0 && root->val + total > sum) //no need to go further
            return;
        */
        path.push_back(root->val);
        
        if (root->left)
            helper(root->left, path, sum, res);
        if (root->right)
            helper(root->right, path, sum, res);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> path;
        helper(root, path, sum, res);
        return res;
    }
};
