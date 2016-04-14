
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
    //this the naive thought i have initially, which is WRONG
    void helper_wrong(struct TreeNode * root, bool stolen, int & sum) {
        if (!root)
            return;
        if (stolen) {
            helper_wrong(root->left, false, sum);
            helper_wrong(root->right, false, sum);
        }
        else {
            sum += root->val;
            helper_wrong(root->left, true, sum);
            helper_wrong(root->right, true, sum);
        }
    }
    pair<int, int> helper(struct TreeNode * root) {
        if (!root)
            return make_pair(0, 0);
        pair<int, int> a = helper(root->left);//the first means root->left->val was take
        pair<int, int> b = helper(root->right);//the first means root->right->val was taken
        int take_curr = a.second+b.second + root->val;
        
        int not_taken_curr = max(a.first, a.second) + max(b.first, b.second);//need to think why
        //cout << root->val << " " << take_curr << " " << not_taken_curr << endl;
        return make_pair(take_curr, not_taken_curr);
    }
    int rob(TreeNode* root) {
        pair<int, int> res = helper(root);
        return max(res.first, res.second);
    }
};
