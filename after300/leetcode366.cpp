
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
    //https://discuss.leetcode.com/topic/49194/10-lines-simple-java-solution-using-recursion-with-explanation
    int helper(TreeNode * root, vector<vector<int>> & res) {
        if (!root)  
            return -1;
        int height = 1 + max(helper(root->left, res), helper(root->right, res));
        if (res.size() < height+1) res.push_back({});
        res[height].push_back(root->val);
        //if really want to remove leaf
        root->left = nullptr;
        root->right = nullptr;
        return height;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
};
