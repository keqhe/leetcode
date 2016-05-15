
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
    //TLE, the naive solution, did not use the condition that it is a complete binary tree
    int countNodes_naive(TreeNode* root) {
        if (!root)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    //O(h^2) solution, think why O(h^2) < O(n)
    int getLeftHeight(struct TreeNode * root) {
        int cnt = 0;
        while (root) {
            cnt ++;
            root = root->left;
        }
        return cnt;
    }
    int getRightHeight(struct TreeNode * root) {
        int cnt = 0;
        while (root) {
            cnt ++;
            root = root->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int a = getLeftHeight(root);
        int b = getRightHeight(root);
        if (a == b)
            return (1<<a) - 1;
        else
            return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
