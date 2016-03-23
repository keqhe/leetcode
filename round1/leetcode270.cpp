
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
    int closestValue(TreeNode* root, double target) {
        double dist = numeric_limits<double>::max();
        int found;
        while (root) {
            double now = abs(target-(double)root->val);
            if (now < dist) {
                dist = now;
                found = root->val;
            }
            if (target < root->val) {
                root = root->left;
            }
            else if (target > root->val) {
                root = root->right;
            }
            else
                return root->val;
        }
        return found;
    }
};
