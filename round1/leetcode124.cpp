
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
    //clean solution: https://leetcode.com/discuss/43797/elegant-java-solution
    int curr_max = numeric_limits<int>::min(); //keep track of max
    int dfs(struct TreeNode *root) {//return the max for the subtree rooted at "root"
        if (!root)  
            return 0;
        int leftM = dfs(root->left);//leftM can be negative
        int rightM = dfs(root->right);//rightM can also be negative
        
        leftM = max(leftM, 0);
        rightM = max(rightM, 0);
        
        curr_max = max(curr_max, root->val+leftM+rightM);
        
        return root->val + max(leftM, rightM);
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root);
        return curr_max;
    }
};
