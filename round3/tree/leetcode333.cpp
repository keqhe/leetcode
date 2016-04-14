
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
    //navie solution, run "validate BST " at each node which results O(nlogn) time complexity
    //the following is a bottom up solution (O(n) time), which is simialr to postorder traversal
    int helper(struct TreeNode * root, long & left, long & right, int &maxSize) {
        if (!root) {
            left = numeric_limits<long>::max();
            right = numeric_limits<long>::min();
            return 0;
        }
        long lMin, lMax;
        long rMin, rMax;
        int l = helper(root->left, lMin, lMax, maxSize);
        int r = helper(root->right, rMin, rMax, maxSize);
        //cout << "for root->val: " << root->val << " its left_max and right_min are: " << lMax << " " << rMin << endl;
        if (l >= 0 && r >= 0) {
            if (lMax < root->val && root->val < rMin) {//left subtree's max < root->val < right subtree's min
                left = lMin == numeric_limits<long>::max() ? root->val : lMin;
                right = rMax == numeric_limits<long>::min() ? root->val : rMax;
                
                maxSize = max(maxSize, l+r+1);
                return l+r+1;
            }
        }
        return -1;
    }
    int largestBSTSubtree(TreeNode* root) {
        int maxSize = 0;
        long left, right;
        helper(root, left, right, maxSize);
        return maxSize;
    }
};
