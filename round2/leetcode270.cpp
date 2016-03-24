
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
    //ref: https://leetcode.com/discuss/55460/simple-iterative-java-solution-with-explaination
    int closestValue(TreeNode* root, double target) {
        double diff = numeric_limits<double>::max();
        int candidate;
        while (root) {
            if (abs((double)root->val - target) < diff) {
                diff = abs((double)root->val - target);
                candidate = root->val;
            }
            if (root->val == target) {
                return root->val;
            }
            else if (root->val < target){
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return candidate;
    }
};
