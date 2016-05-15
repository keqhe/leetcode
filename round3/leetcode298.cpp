
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
    //time complexity is O(n), similar to bottom up postorder traversal
    int helper(TreeNode* root, int & globalMax) {
        if (!root)
            return 0;
        int a = helper(root->left, globalMax);
        int b = helper(root->right, globalMax);
        //cout << a <<" " <<  b << endl;
        int curr = 1;
        if (root->left && root->val +1 == root->left->val)
            curr = max(curr, a+1);
        if (root->right && root->val + 1 == root->right->val)
            curr = max(curr, b+1);
        //cout << "globalMax1 : " << globalMax << endl;
        globalMax = max(globalMax, curr);
        //cout << "curr: " << curr << endl;
        //cout << "globalMax2 : " << globalMax << endl << endl;
        return curr;
    }
    
    int longestConsecutive(TreeNode* root) {
        int globalMax = 0;
        int res = helper(root, globalMax);
        return globalMax;
    }
};
