
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
    //the following time complexity is O(N)
    void helper(struct TreeNode * root, double target, int & candidate, double & distance) {
        if (!root)
            return;
        if (abs((double)root->val - target) < distance) {
            distance = abs((double)root->val - target);
            candidate = root->val;
        }
        helper(root->left, target, candidate, distance);
        helper(root->right, target, candidate, distance);
    }
    int closestValue_notbest(TreeNode* root, double target) {
        int candidate;
        double distance = numeric_limits<double>::max();
        helper(root, target, candidate, distance);
        return candidate;
    }
    //the following time complexity is O(logN)
    int closestValue(TreeNode* root, double target) {
        double distance = numeric_limits<double>::max();
        int candidate;
        while (root) {
            if (abs((double)root->val - target) < distance) {
                distance = abs((double)root->val - target);
                candidate = root->val;
            }
            if (root->val == target)
                return root->val;
            else if (root->val < target)
                root = root->right;
            else 
                root = root->left;
        }
        return candidate;
    }
};
