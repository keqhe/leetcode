
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
    /*TLE, but i think the logic is correct
    int helper(struct TreeNode* root, bool prev_chosen) {
        if (!root)
            return 0;
        if (prev_chosen) {
            int a = helper(root->left, false) + helper(root->right, false);
            int b = helper(root->left, true) + helper(root->right, true);
            return max(a, b);
        }
        else {
            int a = root->val + helper(root->left, true) + helper(root->right, true);
            int b = helper(root->left, false) + helper(root->right, false);
            return max(a, b);
        }
        
    }
    int rob(TreeNode* root) {
        int a = helper(root, true);
        int b = helper(root, false);
        return max(a, b);
    }*/
    //f1(root), we can rob root if necessary
    //f2(root), we can not rob root 
    //so f2(root) = f1(root->left) + f1(root->right);
    //f1(root) = max(f2(root), root->val + f2(root->left) + f2(root->right));
    //ref: https://leetcode.com/discuss/91652/c-java-python-%26-explanation
    pair<int, int> dfs(struct TreeNode * root) {
        if (!root)
            return make_pair(0, 0);
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int f2 = l.second + r.second;
        int f1 = max(f2, l.first + r.first + root->val);
        return make_pair(f2, f1);//first means we can not take root, second means we can take root
    }
    int rob(TreeNode* root) {
        auto x = dfs(root);
        return max(x.first, x.second);
    }
};
