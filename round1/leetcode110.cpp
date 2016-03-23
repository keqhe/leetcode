
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
    pair<bool, int> checkBalanced(TreeNode * root) {
        if (!root)
            return {true, -1};//why -1? only has root, height = 0;
        pair<bool,int> left_result = checkBalanced(root->left);
        pair<bool, int> right_result = checkBalanced(root->right);
        
        if (left_result.first == false)
            return {false, 0};
        
        else if (right_result.first == false)
            return {false, 0};
        else {
            bool balanced;
            if (abs(left_result.second - right_result.second) <= 1)
                balanced = true;
            else
                balanced = false;
            int height = max(left_result.second, right_result.second) + 1;
            return {balanced, height};
        }
    }
   
    bool isBalanced(TreeNode * root) {
        return checkBalanced(root).first;
    }
    /*
    bool isBalanced2(TreeNode* root) {
        if (!root)
            return true;
        else {
            int left;
            int right;
            left = getHeight(root->left);
            right = getHeight(root->right);
            return (abs(left-right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
        }
    }*/
};
